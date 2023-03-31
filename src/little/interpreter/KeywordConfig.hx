package little.interpreter;

@:structInit
class KeywordConfig {
    @:optional public var VARIABLE_DECLARATION:String = "define";
    @:optional public var FUNCTION_DECLARATION:String = "action";
    @:optional public var TYPE_DECL_OR_CAST:String = "as";
    @:optional public var FUNCTION_RETURN:String = "return";
    @:optional public var NULL_VALUE:String = "nothing";
    @:optional public var TRUE_VALUE:String = "true";
    @:optional public var FALSE_VALUE:String = "false";
    @:optional public var TYPE_DYNAMIC:String = "Anything";
    @:optional public var TYPE_VOID:String = "Void";
    @:optional public var TYPE_INT:String = "Number";
    @:optional public var TYPE_FLOAT:String = "Decimal";
    @:optional public var TYPE_BOOLEAN:String = "Boolean";
    @:optional public var TYPE_STRING:String = "Characters";
    /**
        represent the "type" type:
        for example: `5` is of type `Number`, and `Number` is of type `Type`
    **/
    @:optional public var TYPE_MODULE:String = "Type";

    @:optional public var MAIN_MODULE_NAME:String = "Main";
    @:optional public var REGISTERED_MODULE_NAME:String = "Registered";

    @:optional public var PRINT_FUNCTION_NAME:String = "print";
    @:optional public var RAISE_ERROR_FUNCTION_NAME:String = "error";
    @:optional public var READ_FUNCTION_NAME:String = "read";
    @:optional public var RUN_CODE_FUNCTION_NAME:String = "run";

    /**
    	No need to ever change this, this is a parser-only feature
    **/
    @:optional public var TYPE_UNKNOWN:String = "Unknown";

    @:optional public var CONDITION_TYPES:Array<String> = [];
    @:optional public var SPECIAL_OR_MULTICHAR_SIGNS:Array<String> = ["++", "--", "**", "+=", "-=", ">=", "<=", "==", "&&", "||", "^^", "!="];

    /**
    	When changing this to a multi-char sign (such as "->"), remember to also push that sign to `SPECIAL_OR_MULTICHAR_SIGNS`, so it would be parsed correctly.
    **/
    @:optional public var PROPERTY_ACCESS_SIGN:String = ".";
    @:optional public var EQUALS_SIGN:String = "==";
    @:optional public var NOT_EQUALS_SIGN:String = "!=";
    @:optional public var XOR_SIGN:String = "^^";
    @:optional public var OR_SIGN:String = "||";
    @:optional public var AND_SIGN:String = "&&";

    @:optional public var FOR_LOOP_IDENTIFIERS:{FROM:String, TO:String, JUMP:String} = {FROM: "from", TO: "to", JUMP: "jump"};
}