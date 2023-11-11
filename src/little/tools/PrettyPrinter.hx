package little.tools;

import haxe.ds.ArraySort;
import vision.algorithms.Radix;
import little.interpreter.Operators;
import little.interpreter.Interpreter;
using StringTools;
using little.tools.TextTools;

import little.parser.Tokens;

import little.Keywords.*;

class PrettyPrinter {
    
    public static function printParserAst(ast:Array<ParserTokens>, ?spacingBetweenNodes:Int = 6) {
		if (ast == null) return "null (look for errors in input)";
		s = " ".multiply(spacingBetweenNodes);
		var unfilteredResult = getTree(Expression(ast, null), [], 0, true);
		var filtered = "";
		for (line in unfilteredResult.split("\n")) {
			if (line == "└─── Expression")
				continue;
			filtered += line.substring(spacingBetweenNodes - 1) + "\n";
		}
		return "\nAst\n" + filtered;
	}

	static function prefixFA(pArray:Array<Int>) {
		var prefix = "";
		for (i in 0...l) {
			if (pArray[i] == 1) {
				prefix += "│" + s.substring(1);
			} else {
				prefix += s;
			}
		}
		return prefix;
	}

	static function pushIndex(pArray:Array<Int>, i:Int) {
		var arr = pArray.copy();
		arr[i + 1] = 1;
		return arr;
	}

	static var s = "";
	static var l = 0;

	static function getTree(root:ParserTokens, prefix:Array<Int>, level:Int, last:Bool):String {
		l = level;
		var t = if (last) "└" else "├";
		var c = "├";
		var d = "───";
		if (root == null)
			return ''; //'${prefixFA(prefix)}$t$d SetLine($line)\n'
		switch root {
			case SetLine(line): return '${prefixFA(prefix)}$t$d SetLine($line)\n';
            case SplitLine: return '${prefixFA(prefix)}$t$d SplitLine\n';
            case Characters(string): return '${prefixFA(prefix)}$t$d "$string"\n';
			case Module(name): return '${prefixFA(prefix)}$t$d Module: $name\n';
			case ErrorMessage(name): return '${prefixFA(prefix)}$t$d Error: $name\n';
			case Documentation(doc): return '${prefixFA(prefix)}$t$d Documentation: ${doc.replace("\n", "\n" + prefixFA(prefix) + '│                  ')}\n';
			case NoBody:  return '${prefixFA(prefix)}$t$d <no body>\n';
			case External(haxeValue): return '${prefixFA(prefix)}$t$d External Haxe Value Identifier: [$haxeValue]\n';
			case ExternalCondition(use): return '${prefixFA(prefix)}$t$d External Haxe Condition Identifier: [$use]\n';
            case Decimal(num): return '${prefixFA(prefix)}$t$d $num\n';
            case Number(num): return '${prefixFA(prefix)}$t$d $num\n';
            case FalseValue: return '${prefixFA(prefix)}$t$d ${Keywords.FALSE_VALUE}\n';
            case TrueValue: return '${prefixFA(prefix)}$t$d ${Keywords.TRUE_VALUE}\n';
            case NullValue: return '${prefixFA(prefix)}$t$d ${Keywords.NULL_VALUE}\n';
			case Variable(name, type, doc):
				{
					var title = '${prefixFA(prefix)}$t$d Variable Creation\n';
					if (doc != null) title += getTree(doc, prefix.copy(), level + 1, false);
					title += getTree(name, prefix.copy(), level + 1, type == null);
					if (type != null) title += getTree(type, prefix.copy(), level + 1, true);
					return title;
				}
			case Function(name, params, type, doc):
				{
					var title = '${prefixFA(prefix)}$t$d Function Creation\n';
					if (doc != null) title += getTree(doc, prefix.copy(), level + 1, false);
					title += getTree(name, prefix.copy(), level + 1, false);
					title += getTree(params, prefix.copy(), level + 1, type == null);
					if (type != null) title += getTree(type, prefix.copy(), level + 1, true);
					return title;
				}
			case Condition(name, exp, body, type):
				{
					var title = '${prefixFA(prefix)}$t$d Condition\n';
					title += getTree(name, prefix.copy(), level + 1, false);
					title += getTree(exp, pushIndex(prefix, level), level + 1, false);
					title += getTree(body, prefix.copy(), level + 1, type == null);
					title += getTree(type, prefix.copy(), level + 1, true);
					return title;
				}
			case Read(name):
				return '${prefixFA(prefix)}$t$d Read: $name\n';
			case Write(assignees, value, type):
				{
					return'${prefixFA(prefix)}$t$d Variable Write\n${getTree(PartArray(assignees), pushIndex(prefix, level), level + 1, false)}${getTree(value, prefix.copy(), level + 1, type == null)}${getTree(type, prefix.copy(), level + 1, true)}';
				}
			case Sign(value):
				{
					return '${prefixFA(prefix)}$t$d $value\n';
				}
            case TypeDeclaration(value, type): 
				{
					return '${prefixFA(prefix)}$t$d Type Declaration\n${getTree(value, if (type == null) prefix.copy() else pushIndex(prefix, level), level + 1, type == null)}${getTree(type, prefix.copy(), level + 1, true)}';
            	}
			case Identifier(value): {
				return '${prefixFA(prefix)}$t$d $value\n';
			}
			case Expression(parts, type):
				{
					if (parts.length == 0)
						return '${prefixFA(prefix)}$t$d <empty expression>\n';
					var strParts = ['${prefixFA(prefix)}$t$d Expression\n${getTree(type, prefix.copy(), level + 1, false)}'].concat([
						for (i in 0...parts.length - 1) getTree(parts[i], pushIndex(prefix, level), level + 1, false)
					]);
					strParts.push(getTree(parts[parts.length - 1], prefix.copy(), level + 1, true));
					return strParts.join("");
				}
            case Block(body, type): {
                if (body.length == 0)
                    return '${prefixFA(prefix)}$t$d <empty block>\n';
                var strParts = ['${prefixFA(prefix)}$t$d Block\n${getTree(type, prefix.copy(), level + 1, false)}'].concat([
                    for (i in 0...body.length - 1) getTree(body[i], pushIndex(prefix, level), level + 1, false)
                ]);
                strParts.push(getTree(body[body.length - 1], prefix.copy(), level + 1, true));
                return strParts.join("");
            }
			case PartArray(body): {
                if (body.length == 0)
                    return '${prefixFA(prefix)}$t$d <empty array>\n';
                var strParts = ['${prefixFA(prefix)}$t$d Part Array\n'].concat([
                    for (i in 0...body.length - 1) getTree(body[i], pushIndex(prefix, level), level + 1, false)
                ]);
                strParts.push(getTree(body[body.length - 1], prefix.copy(), level + 1, true));
                return strParts.join("");
            }
			case FunctionCall(name, params):
				{
					var title = '${prefixFA(prefix)}$t$d Function Call\n';
					title += getTree(name, pushIndex(prefix, level), level + 1, false);
					title += getTree(params, prefix.copy(), level + 1, true);
					return title;
				}
			case Return(value, type): {
				return '${prefixFA(prefix)}$t$d Return\n${getTree(value, prefix.copy(), level + 1, type == null)}${getTree(type, prefix.copy(), level + 1, true)}';
			}
			case PropertyAccess(name, property): {
				return '${prefixFA(prefix)}$t$d Property Access\n${getTree(name, pushIndex(prefix, level), level + 1, false)}${getTree(property, prefix.copy(), level + 1, true)}';
			}
		}
		return "";
	}









	public static function parseParamsString(params:Array<ParserTokens>, isExpected:Bool = true) {
		if (isExpected) {
			var str = [];
			for (param in params) {
				switch param {
					case Variable(name, type): {
						str.push('${Interpreter.stringifyTokenValue(name)} ${Keywords.TYPE_DECL_OR_CAST} ${Interpreter.stringifyTokenValue(type != null ? type : Identifier(Keywords.TYPE_DYNAMIC))}');
					}
					case _:
				}
			}
			if (str.length == 0) return "no parameters";
			return str.join(", ");
		} else {
			var str = [];
			for (param in params) {
				str.push(Interpreter.stringifyTokenIdentifier(param));
			}
			if (str.length == 0) return "no parameters";
			return str.join(", ");
		}
	}


	static var indent = "";

	public static  function stringify(?code:Array<ParserTokens>, ?token:ParserTokens) {
		if (token != null) code = [token];
		var s = "";

		for (token in code) {
			switch token {
				case SetLine(line):s += '\n$indent';
				case SplitLine: s += ", ";
				case Variable(name, type): s += '$VARIABLE_DECLARATION $name ${if (type != null) '$TYPE_DECL_OR_CAST ${stringify(type)}' else ''}';
				case Function(name, params, type): s += '$FUNCTION_DECLARATION ${stringify(name)}(${stringify(params)}) ${if (type != null) '$TYPE_DECL_OR_CAST ${stringify(type)}' else ''}';
				case Condition(name, exp, body, type): 
					indent += "	";
					s += '${stringify(name)} (${stringify(exp)}) \n${stringify(body)} ${if (type != null) '$TYPE_DECL_OR_CAST ${stringify(type)}' else ''}';
					indent = indent.subtract("	");
				case Read(name): s += stringify(name);
				case Write(assignees, value, type): s += [assignees.concat([value]).map(t -> stringify(t)).join(" = ")];
				case Identifier(word): s += word;
				case TypeDeclaration(value, type): s += '$TYPE_DECL_OR_CAST ${stringify(type)}';
				case FunctionCall(name, params): s += '${stringify(name)}(${stringify(params)})';
				case Return(value, type): s += '$FUNCTION_RETURN ${stringify(value)}';
				case Expression(parts, type): s += stringify(parts);
				case Block(body, type): 
					indent += "	";
					s += '{${stringify(body)}} ${if (type != null) '$TYPE_DECL_OR_CAST ${stringify(type)}' else ''}';
					indent = indent.subtract("	");
				case PartArray(parts): s += stringify(parts);
				case PropertyAccess(name, property): s += '${stringify(name)}$PROPERTY_ACCESS_SIGN${stringify(property)}';
				case Sign(sign): s += " " + sign + " ";
				case Number(num): s += num;
				case Decimal(num): s += num;
				case Characters(string): s += '"' + string + '"';
				case Documentation(doc): s += '"""' + doc + '"""';
				case Module(name): 
				case External(get):
				case ExternalCondition(use):
				case ErrorMessage(msg):
				case NullValue: s += NULL_VALUE;
				case TrueValue: s += TRUE_VALUE;
				case FalseValue: s += FALSE_VALUE;
				case NoBody:
			}
		}

		return s;
	}

	public static function prettyPrintOperatorPriority(priority:Map<Int, Array<{sign:String, side:OperatorType}>>) {
		var sortedKeys = [for (x in priority.keys()) x];
		ArraySort.sort(sortedKeys, (x, y) -> x - y);
		
		var string = "";

		for (key in sortedKeys) {
			string += '$key: (';
			for (obj in priority[key]) {
				if (obj.side == LHS_RHS) string += '_${obj.sign}_';
				else if (obj.side == LHS_ONLY) string += '_${obj.sign}';
				else if (obj.side == RHS_ONLY) string += '${obj.sign}_';

				string += ', ';
			}
			string = string.replaceLast(', ', ')') + '\n';
		}

		return string;
	}
}