package little.tools;

import little.interpreter.Actions;
import little.interpreter.Operators;
import haxe.exceptions.ArgumentException;
import little.interpreter.Operators.OperatorType;
import little.interpreter.Runtime;
import haxe.extern.EitherType;
import little.lexer.Lexer;
import little.parser.Parser;
import little.interpreter.Interpreter;
import little.parser.Tokens.ParserTokens;
import little.interpreter.memory.MemoryObject;
import little.Little.*;
import little.Keywords.*;

using little.tools.Plugins;
@:access(little.Little)
@:access(little.interpreter.Runtime)
class Plugins {
	/**
		Registers an entire Haxe class's static fields & methods, to allow accessing them through Little. for example:

		doing:  

			Little.plugin.registerHaxeClass(Data.getClassInfo("Math"));

		Will let you access all of Math's static fields & methods through little:
		```haxe
		print(Math.sqrt(4) + Math.max(2, {define i = 3, i}))
		```

		@param stats Data about the class, obtained by using `Data.getClassInfo("YourClassName")`
		@param littleClassName When provided, remaps the class in little, placing the properties inside the value of `littleClassName` instead of the class name given previously.
	**/
	public static function registerHaxeClass(stats:Array<ItemInfo>, ?littleClassName:String) {

		if (stats.length == 0) {
			return;
		}
        littleClassName = littleClassName != null ? littleClassName : stats[0].className;
		var fieldValues = new Map<String, Dynamic>();
		var fieldFunctions = new Map<String, Dynamic>();
		var cls = Type.resolveClass(stats[0].className);

		// Iterate over the fields of the class
		for (s in stats) {
            if (s.isStatic) {
                var field = s.name;
			    // Check if the field is a static field
			    // Get the field value and store it in the fieldValues map
			    var value = Reflect.field(cls, field);
			    // Check if the field is a function (i.e., a method)
			    if (Reflect.isFunction(value)) {
			    	// Store the function in the fieldFunctions map
                    
			    	fieldFunctions.set(field, value);
			    } else {
                    fieldValues.set(field, value);
                } 
            } else {
                var field = s.name;
                var value = Reflect.field(Type.createEmptyInstance(cls), field);
                if (Reflect.isFunction(value)) {
                    fieldFunctions.set(field, (obj:ParserTokens, paramsArray) -> {
                        
                        return Reflect.callMethod(Conversion.toHaxeValue(obj), Reflect.field(Conversion.toHaxeValue(obj), field), paramsArray);
                    });
                } else {
                    fieldValues.set(field, (obj:ParserTokens) -> {
                        return Reflect.field(Conversion.toHaxeValue(obj), field);
                    });
                }
            }
           

		}

		//// Test the maps by printing the values of Math.PI and Math.sqrt()
		// trace(fieldValues);
		// trace(fieldFunctions);

		var motherObj = new MemoryObject(Module(littleClassName), [], null, Module(TYPE_MODULE), true); 

		for (instance in stats) {
			//trace(instance.fieldType, instance.allowWrite, instance.name, instance.parameters, instance.returnType);
			switch (instance.fieldType) {
				case "var":
					{
                        if (instance.isStatic) {
                            var value:ParserTokens = Conversion.toLittleValue(fieldValues[instance.name]);
						    var type:ParserTokens = Identifier(Conversion.toLittleType(instance.returnType));
						    motherObj.props.set(instance.name, new MemoryObject(value, [] /*Should this be implemented?*/, null, type, true, motherObj));
                        } else {
                            var value:ParserTokens = External(params -> {
                                return Conversion.toLittleValue(fieldValues[instance.name](params[0])); // params[0] should be the current var's value when using the function
                            });
                            var type:ParserTokens = Identifier(Conversion.toLittleType(instance.returnType));
                            motherObj.props.set(instance.name, new MemoryObject(value, [] /*Should this be implemented?*/, [
                                Variable(Identifier("value " /* That extra space is used to differentiate between non-static fields and functions. Todo: Pretty bad solution */), Identifier(littleClassName))
                            ], type, true, false, true, motherObj));
                        }
						
					}
				case "function": {
                    if (instance.isStatic) {
                        var value:ParserTokens = External((args) -> {
					    	return Conversion.toLittleValue(Reflect.callMethod(null, fieldFunctions[instance.name], [for (arg in args) Conversion.toHaxeValue(arg)]));
					    });

					    var type:ParserTokens = Identifier(Conversion.toLittleType(instance.returnType));
					    var params = [];
					    for (param in instance.parameters) 
					    	params.push(Variable(Identifier(param.name), Identifier(param.type)));

					    motherObj.props.set(instance.name, new MemoryObject(value, [] /*Should this be implemented?*/, params, type, true, motherObj));
                    } else {
                        var value:ParserTokens = External((args) -> {
                            var obj = args.shift();
                            var params = [for (a in args) Conversion.toHaxeValue(a)];
                            return Conversion.toLittleValue(fieldFunctions[instance.name](obj, params));
					    });

					    var type:ParserTokens = Identifier(Conversion.toLittleType(instance.returnType));
					    var params = [];
					    for (param in instance.parameters) 
					    	params.push(Variable(Identifier(param.name), Identifier(param.type)));
                        params.unshift(Variable(Identifier("value"), Identifier(littleClassName)));
					    motherObj.props.set(instance.name, new MemoryObject(value, [] /*Should this be implemented?*/, params, type, true, false, true, motherObj));
                    }

                    
				}
			}
		}

		Interpreter.memory.set(littleClassName, motherObj);
	}

	/**
		Registers a haxe function inside Little code.
		@param stats Data about the function, obtained using `Data.getFunctionInfo("functionName", "moduleName")`.
		@param littleName When provided, remaps the function name in Little code. This name allows property access, such as `SomeType.functionName`
	**/
	public static function registerHaxeFunction(stats:ItemInfo, ?littleName:String) {
		var cls = Type.resolveClass(stats.className);
		var func = Reflect.field(cls, stats.name);

		var motherObj = new MemoryObject(Module(stats.className), [], null, Module(TYPE_MODULE), true);
		if (littleName != null) {
			motherObj = Actions.memory.object;
			var objects = littleName.split(Little.keywords.PROPERTY_ACCESS_SIGN);
			stats.name = objects.pop();
			for (name in objects) {
				if (motherObj.get(name) != null) {
					motherObj = motherObj.get(name);
				} else {
					var child = new MemoryObject(NullValue, [], null, Module(TYPE_DYNAMIC), true); // No reason to create a type, it's not used as one.
					motherObj.set(name, child);
					motherObj = child;
				}
			}
		}

		if (stats.isStatic) {
			var value:ParserTokens = External((args) -> {
				return Conversion.toLittleValue(Reflect.callMethod(null, func, [for (arg in args) Conversion.toHaxeValue(arg)]));
			});

			var type:ParserTokens = Identifier(Conversion.toLittleType(stats.returnType));
			var params = [];
			for (param in stats.parameters) 
				params.push(Variable(Identifier(param.name), Identifier(param.type)));

			motherObj.props.set(stats.name, new MemoryObject(value, [] /*Should this be implemented?*/, params, type, true, motherObj));
		}
	}







































    /**
        registers a haxe value/property inside Little code.

        @param variableName the name of the variable, for usage in Little code.
        @param variableModuleName the module at which the variable "is declared". errors & logs point to this module.
        @param allowWriting Whether writing to this variable is allowed or not.
        @param staticValue **Option 1** - a static value to assign to this variable
        @param valueGetter **Option 2** - a function that returns a value that this variable gives when accessed.
        @param valueSetter a function that dispatches whenever this value is assigned to. Takes effect when `allowWriting == true`.
    **/
    public static function registerVariable(variableName:String, ?variableModuleName:String, allowWriting:Bool = false, ?staticValue:ParserTokens, ?valueGetter:Void -> ParserTokens, ?valueSetter:ParserTokens -> ParserTokens) {
        Interpreter.memory.set(variableName, new MemoryObject(
            External(params -> {
                var currentModuleName = Little.runtime.currentModule;
                if (variableModuleName != null) Little.runtime.currentModule = variableModuleName;
                return try {
                    var val = if (staticValue != null) staticValue;
                    else valueGetter();
                    Little.runtime.currentModule = currentModuleName;
                    val;
                } catch (e) {
                    Little.runtime.currentModule = currentModuleName;
                    ErrorMessage('External Variable Error: ' + e.details());
                }
            }), 
            [], 
            null,
            null, 
            true, 
            Interpreter.memory.object
        ));

        if (valueSetter != null) {
            Interpreter.memory.get(variableName).valueSetter = function (v) {
                return Interpreter.memory.get(variableName).value = valueSetter(v);
            }
        }
        if (allowWriting == false) { //syntax here explained later on 
            Interpreter.memory.get(variableName).valueSetter = function (v) {
                Runtime.warn(ErrorMessage('Editing the variable $variableName is disallowed. New value is ignored, returning original value.'));
                var currentModuleName = Little.runtime.currentModule;
                if (variableModuleName != null) Little.runtime.currentModule = variableModuleName;
                return try {
                    var val = if (staticValue != null) staticValue;
                    else valueGetter();
                    Little.runtime.currentModule = currentModuleName;
                    val;
                } catch (e) {
                    Little.runtime.currentModule = currentModuleName;
                    ErrorMessage('External Variable Error: ' + e.details());
                }
            }
        }
    }

    /**
    	Allows usage of a function written in haxe inside Little code.

    	@param actionName The name by which to identify the function
    	@param actionModuleName The module from which access to this function is granted. Also, when & if this function ever throws an error/prints to standard output, the name provided here will be present in the error message as the responsible module.
    	@param expectedParameters an `Array<ParserTokens>` consisting of `ParserTokens.Variable`s which contain the names & types of the parameters that should be passed on to the function. For example:
            ```
            [Variable(Identifier(x), Identifier("String"))]
            ```
            **alternatively** - can be normal parameter "list" written in little: 
            ``` 
            define value, define index as Number
            ```
    	@param callback The actual function, which gets an array of the given parameters as little tokens (specifically of type `Expression`, 0 or more of them), and returns a value based on them
    **/
    public static function registerFunction(actionName:String, ?actionModuleName:String, expectedParameters:EitherType<String, Array<ParserTokens>>, callback:Array<ParserTokens> -> ParserTokens) {
        var params = if (expectedParameters is String) {
            Parser.parse(Lexer.lex(expectedParameters));
        } else expectedParameters;

        var memObject = new MemoryObject(
            External(params -> {
                var currentModuleName = Little.runtime.currentModule;
                if (actionModuleName != null) Little.runtime.currentModule = actionModuleName;
                return try {
                    var val = callback(params);
                    Little.runtime.currentModule = currentModuleName;
                    val;
                } catch (e) {
                    Little.runtime.currentModule = currentModuleName;
                    ErrorMessage('External Function Error: ' + e.details());
                }
            }), 
            [], 
            params, 
            null, 
            true
        );

        if (actionModuleName != null) {
            Interpreter.memory.set(actionModuleName, new MemoryObject(Module(actionModuleName), [], null, Module(TYPE_MODULE), true, Interpreter.memory.object));
            memObject.parent = Interpreter.memory.get(actionModuleName);
            Interpreter.memory.get(actionModuleName).props.set(actionName, memObject);
        } else Interpreter.memory.set(actionName, memObject);
    }

    public static function registerCondition(conditionName:String, ?expectedConditionPattern:EitherType<String, Array<ParserTokens>> ,callback:(Array<ParserTokens>, Array<ParserTokens>) -> ParserTokens) {
        CONDITION_TYPES.push(conditionName);

		var params = if (expectedConditionPattern is String) {
            Parser.parse(Lexer.lex(expectedConditionPattern));
        } else expectedConditionPattern;

        Interpreter.memory.set(conditionName, new MemoryObject(
            ExternalCondition((con, body) -> {
                return try {
                    callback(con, body);
                } catch (e) {
                    ErrorMessage('External Condition Error: ' + e.details());
                }
            }), 
            [], 
            params, 
            null, 
            true,
			true,
            Interpreter.memory.object
        ));
    }

    public static function registerProperty(propertyName:String, onObject:String, isType:Bool, ?valueOption1:FunctionInfo, ?valueOption2:VariableInfo) {
        if (isType) {
            if (!Interpreter.memory.exists(onObject) || Interpreter.memory.silentGet(onObject).value.getName() != "Module") {
                Interpreter.memory.set(onObject, new MemoryObject(Module(onObject), [], null, Module(TYPE_MODULE), true));
            }
        } else {
            if (!Interpreter.memory.exists(onObject)) {
                Interpreter.memory.set(onObject, new MemoryObject(NullValue, [], null, Module(TYPE_DYNAMIC), true));
            }
        }

        var memObject:MemoryObject = new MemoryObject();
        var parent = Interpreter.memory.silentGet(onObject);
        if (valueOption2 != null) {
            // Variable
            var info:VariableInfo = valueOption2;
            memObject = new MemoryObject(
                External(params -> {
                    return try {
                        var val = if (info.staticValue != null) info.staticValue;
                        else info.valueGetter(memObject.parent);
                        val;
                    } catch (e) {
                        ErrorMessage('External Variable Error: ' + e.details());
                    }
                }), 
                [], 
                if (!isType) null else [
                    Variable(Identifier("value " /* That extra space is used to differentiate between non-static fields and functions. Todo: Pretty bad solution */), Identifier(onObject))
                ],
                Identifier(info.type), 
                true,
                false,
                isType,
                parent
            );

            if (info.valueSetter != null) {
                memObject.valueSetter = function (v) {
                    return memObject.value = info.valueSetter(memObject.parent, v);
                }
            }

            if (info.allowWriting == false) {// null defaults to true here, so cant use !info.allowWriting
                memObject.valueSetter = function (v) {
                    Runtime.warn(ErrorMessage('Directly editing the property $onObject$PROPERTY_ACCESS_SIGN$propertyName is disallowed. New value is ignored, returning original value.'));
                    return try {
                        var val = if (info.staticValue != null) info.staticValue;
                        else info.valueGetter(memObject.parent);
                        val;
                    } catch (e) {
                        ErrorMessage('External Variable Error: ' + e.details());
                    }
                }
            }
        } else {
            // Function
            var info:FunctionInfo = valueOption1;

            var params = if (info.expectedParameters is String) {
                Parser.parse(Lexer.lex(info.expectedParameters));
            } else info.expectedParameters;
            if (isType) params.unshift(Variable(Identifier("value"), Identifier(onObject)));

            memObject = new MemoryObject(
                External(params -> {
                    return try {
                        var val = info.callback(memObject.parent, params);
                        val;
                    } catch (e) {
                        ErrorMessage('External Function Error: ' + e.details());
                    }
                }), 
                [], 
                params, 
                Identifier(info.type), 
                true,
                false,
                isType,
                parent
            );

            if (info.allowWriting == false) {// null defaults to true here, so cant use !info.allowWriting
                memObject.valueSetter = function (v) {
                    Runtime.throwError(ErrorMessage('Directly editing the property $onObject$PROPERTY_ACCESS_SIGN$propertyName is disallowed. New value is ignored, returning original value.'));
                    return try {
                        var val = info.callback(memObject.parent, params);
                        val;
                    } catch (e) {
                        ErrorMessage('External Function Error: ' + e.details());
                    }
                }
            }
        }
       
        // trace('Adding $propertyName to $onObject');
        parent.props.set(propertyName, memObject);
        
    }

	
	public static function registerStaticField(fieldName:String, type:String, ?valueOption1:StaticFunctionInfo, ?valueOption2:StaticVariableInfo) {
		var typeObject = Interpreter.memory.get(type);

		if (valueOption1 != null) {
			var value = External(params -> {
				var prevModule = Runtime.currentModule;
				Actions.setModule(type);
				return try {
					var val = valueOption1.callback(params);
					Actions.setModule(prevModule);
					val;
				} catch (e) {
					ErrorMessage('External Function Error: ' + e.details());
				}
			});
			var params = if (valueOption1.expectedParameters is String) {
                Parser.parse(Lexer.lex(valueOption1.expectedParameters));
            } else valueOption1.expectedParameters;
			
			var obj = new MemoryObject(
				value, 
				[], 
				params, 
				Module(valueOption1.valueType) ?? Interpreter.getValueType(value), 
				true, false, false, 
				typeObject, 
				valueOption1.doc
			);
			if (!valueOption1.allowWriting) {
				obj.valueSetter = function (v) {
					Runtime.warn(ErrorMessage('Directly editing the property $type$PROPERTY_ACCESS_SIGN$fieldName is disallowed. New value is ignored, returning original value.'));
					return v;
				}
			}

			typeObject.set(fieldName, obj);
		} else {
			var value:ParserTokens, obj:MemoryObject;
			if (valueOption2.staticValue != null) value = valueOption2.staticValue;
			else {
				value = External(params -> {
					var prevModule = Runtime.currentModule;
					return try {
						Actions.setModule(type);
						var val = valueOption2.valueGetter(obj);
						Actions.setModule(prevModule);
						val;
					} catch (e) {
						ErrorMessage('External Variable Error: ' + e.details());
					}
				});
				
				obj = new MemoryObject(
					value,
					[],
					[],
					Module(valueOption2.valueType) ?? Interpreter.getValueType(value),
					true,
					false,
					false,
					typeObject,
					valueOption2.doc
				);

				
				if (!valueOption1.allowWriting) {
					obj.valueSetter = function (v) {
						Runtime.warn(ErrorMessage('Directly editing the property $type$PROPERTY_ACCESS_SIGN$fieldName is disallowed. New value is ignored, returning original value.'));
						return v;
					}
				}

				typeObject.set(fieldName, obj);
			}
		}
	}

	public static function registerInstanceField(fieldName:String, type:String, ?valueOption1:InstanceFunctionInfo, ?valueOption2:InstanceVariableInfo) {
		var typeObject = Interpreter.memory.get(type);

		var obj:MemoryObject;
		if (valueOption1 != null) {
			var value = External(params -> {
				var prevModule = Runtime.currentModule;
				Actions.setModule(type);
				return try {
					var val = valueOption1.callback(obj, params);
					Actions.setModule(prevModule);
					val;
				} catch (e) {
					ErrorMessage('External Function Error: ' + e.details());
				}
			});
			var params = if (valueOption1.expectedParameters is String) {
				Parser.parse(Lexer.lex(valueOption1.expectedParameters));
			} else valueOption1.expectedParameters;

			obj = new MemoryObject(
				value,
				[],
				params,
				Module(valueOption1.valueType) ?? Interpreter.getValueType(value),
				true,
				false,
				true,
				typeObject,
				valueOption1.doc
			);

			if (!valueOption1.allowWriting) {
				obj.valueSetter = function (v) {
					Runtime.warn(ErrorMessage('Directly editing the property $type$PROPERTY_ACCESS_SIGN$fieldName is disallowed. New value is ignored, returning original value.'));
					return v;
				}
			}

			typeObject.set(fieldName, obj);
		} else {
			var value:ParserTokens;
			if (valueOption2.staticValue != null) value = valueOption2.staticValue;
			else {
				value = External(params -> {
					var prevModule = Runtime.currentModule;
					Actions.setModule(type);
					return try {
						var val = valueOption2.valueGetter(obj);
						Actions.setModule(prevModule);
						val;
					} catch (e) {
						ErrorMessage('External Variable Error: ' + e.details());
					}
				});
				
				obj = new MemoryObject(
					value,
					[],
					[],
					Module(valueOption2.valueType) ?? Interpreter.getValueType(value),
					true,
					false,
					true,
					typeObject,
					valueOption2.doc
				);

				if (!valueOption1.allowWriting) {
					obj.valueSetter = function (v) {
						Runtime.warn(ErrorMessage('Directly editing the property $type$PROPERTY_ACCESS_SIGN$fieldName is disallowed. New value is ignored, returning original value.'));
						return v;
					}
				}

				typeObject.set(fieldName, obj);
			}
		}
	}

    static function combosHas(combos:Array<{lhs:String, rhs:String}>, lhs:String, rhs:String) {
        for (c in combos) if (c.rhs == rhs && c.lhs == lhs) return true;
        return false;
    }

    public static function registerSign(symbol:String, info:SignInfo) {

        if (info.operatorType == null || info.operatorType == LHS_RHS) {
            if (info.callback == null && info.singleSidedOperatorCallback != null) 
                throw new ArgumentException("callback", 'Incorrect callback given for operator type ${info.operatorType ?? LHS_RHS} - `singleSidedOperatorCallback` was given, when `callback` was expected');
            else if (info.callback == null)
                throw new ArgumentException("callback", 'No callback given for operator type ${info.operatorType ?? LHS_RHS} (`callback` is null)');
            
            var callbackFunc:(ParserTokens, ParserTokens) -> ParserTokens;

			// A bunch of ifs in order to shorten the final callback function, improves performance a bit
            if (info.lhsAllowedTypes != null && info.rhsAllowedTypes == null && info.allowedTypeCombos == null) {
                callbackFunc = (lhs, rhs) -> {
                    if (!info.lhsAllowedTypes.contains(Interpreter.getValueType(lhs).getParameters()[0])) {
                        var t = Interpreter.getValueType(lhs).getParameters()[0];
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${t}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${Interpreter.getValueType(rhs).getParameters()[0]}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Left operand cannot be of type $t (accepted types: ${info.lhsAllowedTypes})'));
                    }

                    return info.callback(lhs, rhs);
                }
            } else if (info.lhsAllowedTypes == null && info.rhsAllowedTypes != null && info.allowedTypeCombos == null) {
                callbackFunc = (lhs, rhs) -> {
                    if (!info.rhsAllowedTypes.contains(Interpreter.getValueType(rhs).getParameters()[0])) {
                        var t = Interpreter.getValueType(rhs).getParameters()[0];
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${Interpreter.getValueType(lhs).getParameters()[0]}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${t}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Right operand cannot be of type $t (accepted types: ${info.rhsAllowedTypes})'));
                    }

                    return info.callback(lhs, rhs);
                }
            } else if (info.lhsAllowedTypes != null && info.rhsAllowedTypes != null && info.allowedTypeCombos == null) {
                callbackFunc = (lhs, rhs) -> {
                    var rhsType = Interpreter.getValueType(rhs).getParameters()[0],
                        lhsType = Interpreter.getValueType(lhs).getParameters()[0];
                    if (!info.rhsAllowedTypes.contains(Interpreter.getValueType(rhs).getParameters()[0])) {
                        var t = Interpreter.getValueType(rhs).getParameters()[0];
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${Interpreter.getValueType(lhs).getParameters()[0]}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${t}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Right operand cannot be of type $t (accepted types: ${info.rhsAllowedTypes})'));
                    }
					
                    if (!info.rhsAllowedTypes.contains(Interpreter.getValueType(lhs).getParameters()[0])) {
                        var t = Interpreter.getValueType(lhs).getParameters()[0];
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${Interpreter.getValueType(lhs).getParameters()[0]}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${t}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Left operand cannot be of type $t (accepted types: ${info.lhsAllowedTypes})'));
                    }

                    return info.callback(lhs, rhs);
                }
            } else if (info.lhsAllowedTypes != null && info.rhsAllowedTypes == null && info.allowedTypeCombos != null) {
                callbackFunc = (lhs, rhs) -> {
                    var r = Interpreter.getValueType(rhs).getParameters()[0];
                    var l = Interpreter.getValueType(lhs).getParameters()[0];
                    if (!info.lhsAllowedTypes.contains(l) && !info.allowedTypeCombos.containsCombo(l, r)) {
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${l}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${r}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Right operand cannot be of type $r while left operand is of type $l (accepted types for left operand: ${info.lhsAllowedTypes}, accepted type combinations: ${info.allowedTypeCombos.map(object -> '${object.rhs} $symbol ${object.lhs}')})'));
                    }

                    return info.callback(lhs, rhs);
                }
            } else if (info.lhsAllowedTypes == null && info.rhsAllowedTypes != null && info.allowedTypeCombos != null) {
                callbackFunc = (lhs, rhs) -> {
                    var r = Interpreter.getValueType(rhs).getParameters()[0];
                    var l = Interpreter.getValueType(lhs).getParameters()[0];
                    if (!info.rhsAllowedTypes.contains(r) && !info.allowedTypeCombos.containsCombo(l, r)) {
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${l}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${r}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Right operand cannot be of type $r while left operand is of type $l (accepted types for right operand: ${info.rhsAllowedTypes}, accepted type combinations: ${info.allowedTypeCombos.map(object -> '${object.rhs} $symbol ${object.lhs}')})'));
                    }

                    return info.callback(lhs, rhs);
                }
            } else if (info.lhsAllowedTypes != null && info.rhsAllowedTypes != null && info.allowedTypeCombos != null) {
                callbackFunc = (lhs, rhs) -> {
                    var rhsType = Interpreter.getValueType(rhs).getParameters()[0],
                        lhsType = Interpreter.getValueType(lhs).getParameters()[0];
                    if (!info.rhsAllowedTypes.contains(rhsType) && !info.allowedTypeCombos.containsCombo(lhsType, rhsType)) {
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${lhsType}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${rhsType}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Right operand cannot be of type $rhsType (accepted types: ${info.rhsAllowedTypes}, accepted type combinations: ${info.allowedTypeCombos.map(object -> '${object.rhs} $symbol ${object.lhs}')})'));
                    }
					
                    if (!info.rhsAllowedTypes.contains(lhsType) && !info.allowedTypeCombos.containsCombo(lhsType, rhsType)) {
                        return Little.runtime.throwError(ErrorMessage('Cannot preform ${lhsType}(${Interpreter.stringifyTokenIdentifier(lhs)}) $symbol ${rhsType}(${Interpreter.stringifyTokenIdentifier(rhs)}) - Left operand cannot be of type $lhsType (accepted types: ${info.lhsAllowedTypes}, accepted type combinations: ${info.allowedTypeCombos.map(object -> '${object.rhs} $symbol ${object.lhs}')})'));
                    }

                    return info.callback(lhs, rhs);
                }
            } else callbackFunc = info.callback;

			Little.operators.add(symbol, LHS_RHS, info.priority, callbackFunc);
        } else { // One sided operator
			if (info.singleSidedOperatorCallback == null && info.callback != null) 
                throw new ArgumentException("singleSidedOperatorCallback", 'Incorrect callback given for operator type ${info.operatorType} - `callback` was given, when `singleSidedOperatorCallback` was expected');
            else if (info.singleSidedOperatorCallback == null)
                throw new ArgumentException("singleSidedOperatorCallback", 'No callback given for operator type ${info.operatorType ?? LHS_RHS} (`singleSidedOperatorCallback` is null)');
            
			var callbackFunc:ParserTokens -> ParserTokens;

			if (info.operatorType == LHS_ONLY) {
				callbackFunc = (lhs) -> {
					var l = Interpreter.getValueType(lhs).getParameters()[0];
					if (!info.lhsAllowedTypes.contains(l)) {
						return Little.runtime.throwError(ErrorMessage('Cannot perform $l(${Interpreter.stringifyTokenIdentifier(lhs)})$symbol - Operand cannot be of type $l (accepted types: ${info.lhsAllowedTypes})'));
					}

					return info.singleSidedOperatorCallback(lhs);
				}
			} else {
				callbackFunc = (rhs) -> {
					var r = Interpreter.getValueType(rhs).getParameters()[0];
					if (!info.rhsAllowedTypes.contains(r)) {
						return Little.runtime.throwError(ErrorMessage('Cannot perform $symbol$r(${Interpreter.stringifyTokenIdentifier(rhs)}) - Operand cannot be of type $r (accepted types: ${info.rhsAllowedTypes})'));
					}

					return info.singleSidedOperatorCallback(rhs);
				}
			} 

			Little.operators.add(symbol, info.operatorType, info.priority, callbackFunc);
        }
    }




















    static function containsCombo(array:Array<{lhs:String, rhs:String}>, lhs:String, rhs:String):Bool {
        for (a in array) {
            if (a.lhs == lhs && a.rhs == rhs) return true;
        }
        return false;
    }
}

typedef ItemInfo = {
	className:String,
	name:String,
    doc:String,
	parameters:Array<{name:String, type:String, optional:Bool}>,
	returnType:String,
	fieldType:String,
	allowWrite:Bool,
    isStatic:Bool
}

typedef FunctionInfo = {
    expectedParameters:EitherType<String, Array<ParserTokens>>,
    callback:(MemoryObject, Array<ParserTokens>) -> ParserTokens, //parent, params to value
    ?allowWriting:Bool,
    ?type:String
}
typedef StaticFunctionInfo = {
    expectedParameters:EitherType<String, Array<ParserTokens>>,
    callback:(Array<ParserTokens>) -> ParserTokens, //parent, params to value
    ?allowWriting:Bool,
	?valueType:String,
	?doc:String
}

typedef StaticVariableInfo = {
	?staticValue:ParserTokens,
	?valueType:String,
	?valueGetter:MemoryObject -> ParserTokens, // this to value
	?valueSetter:(MemoryObject, ParserTokens) -> ParserTokens, // parent, provided value to value
	?allowWriting:Bool,
	?doc:String
}

typedef InstanceFunctionInfo = {
    expectedParameters:EitherType<String, Array<ParserTokens>>,
    callback:(thisObject:MemoryObject, Array<ParserTokens>) -> ParserTokens, //parent, params to value
	?valueType:String,
    ?allowWriting:Bool,
    ?type:String,
	?doc:String
}

typedef InstanceVariableInfo = {
	?staticValue:ParserTokens,
	?valueType:String,
	?valueGetter:MemoryObject -> ParserTokens, // this to value
	?valueSetter:(MemoryObject, ParserTokens) -> ParserTokens, // parent, provided value to value
	?allowWriting:Bool,
	?doc:String
}


typedef VariableInfo = {
    ?staticValue:ParserTokens, 
    ?valueGetter:MemoryObject -> ParserTokens, //parent to value
    ?valueSetter:(MemoryObject, ParserTokens) -> ParserTokens, //parent, provided value to value
    ?allowWriting:Bool,
    ?type:String
}

typedef SignInfo = {
    ?lhsAllowedTypes:Array<String>,
    ?rhsAllowedTypes:Array<String>,
    ?allowedTypeCombos:Array<{lhs:String, rhs:String}>,
    ?callback:(ParserTokens, ParserTokens) -> ParserTokens,
    ?singleSidedOperatorCallback:ParserTokens -> ParserTokens,
    ?operatorType:OperatorType,
	/**
		@see Operators.setPriority
	**/
	?priority:String,
}