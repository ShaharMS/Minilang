package js_example;

import js.html.SpanElement;
import js.html.TableColElement;
import js.html.Node;
import js.Syntax;
import little.Keywords;
import haxe.display.Display.Keyword;
import js.html.TableRowElement;
import js.html.TableElement;
import js.html.TextAreaElement;
import js.html.Document;
import little.interpreter.Runtime;
import little.Little;
import js.Browser;

using js_example.JsExample;
import little.Keywords.*;
class JsExample {
    
    var d = Browser.document;

    public function new() {
        var input:TextAreaElement = cast d.getElementById("input");
        var ast:TextAreaElement = cast d.getElementById("ast");
        var output:TextAreaElement = cast d.getElementById("output");

        var version:SpanElement = cast d.getElementById("version");
        var buildDate:SpanElement = cast d.getElementById("build-date");
        var buildNumber:SpanElement = cast d.getElementById("build-number");

        buildNumber.innerText = JsMacro.getBuildCount();
        buildDate.innerText = JsMacro.getBuildTime();

        trace(input, ast, output);
        input.addEventListener("keyup", function(_) {
			try {
                trace(input.value);
				ast.value = little.tools.PrettyPrinter.printInterpreterAst(little.interpreter.Interpreter.convert(...little.parser.Parser.parse(little.lexer.Lexer.lex(input.value))));
			} catch (e) {}

			try {
                trace(input.value);
                Little.reset();
				Little.run(input.value, true);
				output.value = Little.runtime.stdout.output;
			} catch (e) {}
		});

        input.onkeydown = function (e) {
            if (e.key == 'Tab') {
                e.preventDefault();
                var start = input.selectionStart;
                var end = input.selectionEnd;

                // set textarea value to: text before caret + tab + text after caret
                input.value = input.value.substring(0, start) + "\t" + input.value.substring(end);

                // put caret at right position again
                input.selectionStart = input.selectionEnd = start + 1;
            }
        }

        var keywordTable:TableElement = cast d.getElementById("k-table-body");

        function update() {
            var firstRow = true;
            for (row in keywordTable.rows) {
                if (firstRow) {
                    firstRow = false;
                    continue;
                }
                var p = row.getElementsByTagName("p")[0];
                var input = row.getElementsByTagName("input")[0];
                p.innerText = getCodeExample(input.id);
                p.onchange();
            }
        }
        

        for (keyword in ["VARIABLE_DECLARATION", "FUNCTION_DECLARATION", "NULL_VALUE", "RUN_CODE_FUNCTION_NAME", "TYPE_DECL_OR_CAST", "TYPE_FLOAT", "TYPE_BOOLEAN", "TYPE_STRING", "TYPE_MODULE", "FUNCTION_RETURN", "READ_FUNCTION_NAME", "TYPE_DYNAMIC", "PROPERTY_ACCESS_SIGN", "TRUE_VALUE", "TYPE_INT", "FALSE_VALUE", "RAISE_ERROR_FUNCTION_NAME", "TYPE_SIGN", "PRINT_FUNCTION_NAME", "TYPE_CAST_FUNCTION_PREFIX", "EQUALS_SIGN", "NOT_EQUALS_SIGN", "LARGER_SIGN", "SMALLER_SIGN", "LARGER_EQUALS_SIGN", "SMALLER_EQUALS_SIGN", "AND_SIGN", "OR_SIGN", "XOR_SIGN"]) {
            var row = d.createTableRowElement();

            var usage = d.createTextNode(keyword.snakeToTitleCase());

            var input = d.createInputElement();
            input.id = keyword;
            input.placeholder = "single word, e.g. " + Reflect.field(Keywords.defaultKeywordSet, keyword);
            input.onchange = () -> {
                Reflect.setField(Keywords, keyword, input.value != null ? (input.value != "" ? input.value : Reflect.field(Keywords.defaultKeywordSet, keyword)) : Reflect.field(Keywords.defaultKeywordSet, keyword));
                update();
            }

            var p = d.createParagraphElement();
            
            var td1 = d.createTableCellElement();
            td1.appendChild(usage);
            var td2 = d.createTableCellElement();
            td2.appendChild(input);
            var td3 = d.createTableCellElement();
            td3.appendChild(p);

            row.appendChild(td1);
            row.appendChild(td2);
            row.appendChild(td3);

            keywordTable.appendChild(row);
        }

        Syntax.plainCode("Highlighter.registerOnParagraphs()");
        Syntax.plainCode('document.getElementById("input").dispatchEvent(new Event("onkeyup"));');

        update();

    }

    public function getCodeExample(keyword:String) {
        return switch keyword {
            case "VARIABLE_DECLARATION": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_INT = 8';
            case "FUNCTION_DECLARATION": '$FUNCTION_DECLARATION y($VARIABLE_DECLARATION parameter, $VARIABLE_DECLARATION times $TYPE_DECL_OR_CAST $TYPE_INT) $TYPE_DECL_OR_CAST $TYPE_STRING =  {\n&nbsp;&nbsp;&nbsp;&nbsp;$FUNCTION_RETURN parameter * times\n}\n$PRINT_FUNCTION_NAME(y("Hey", 3))';
            case "NULL_VALUE": 'if (x == $NULL_VALUE) {}\n$VARIABLE_DECLARATION x = $NULL_VALUE';
            case "RUN_CODE_FUNCTION_NAME": '$RUN_CODE_FUNCTION_NAME("$PRINT_FUNCTION_NAME(5 + 3)")';
            case "RAISE_ERROR_FUNCTION_NAME": '$RAISE_ERROR_FUNCTION_NAME("My Own Custom Error! :D")';
            case "PRINT_FUNCTION_NAME": '$PRINT_FUNCTION_NAME("Hello World")';
            case "TYPE_DECL_OR_CAST": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_STRING\nx = $TRUE_VALUE $TYPE_DECL_OR_CAST $TYPE_STRING //"$TRUE_VALUE"';
			case "TYPE_CAST_FUNCTION_PREFIX": 'if (1$PROPERTY_ACCESS_SIGN$TYPE_CAST_FUNCTION_PREFIX$TYPE_BOOLEAN()) {\n&nbsp;&nbsp;&nbsp;&nbsp;$PRINT_FUNCTION_NAME("$TRUE_VALUE"$PROPERTY_ACCESS_SIGN$TYPE_CAST_FUNCTION_PREFIX$TYPE_BOOLEAN()$PROPERTY_ACCESS_SIGN$TYPE_CAST_FUNCTION_PREFIX$TYPE_INT())\n}';
            case "TYPE_FLOAT": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_FLOAT = 8.8';
            case "TYPE_INT": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_INT = 8';
            case "TYPE_BOOLEAN": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_BOOLEAN = $TRUE_VALUE || $FALSE_VALUE';
            case "TYPE_STRING": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_STRING = "Hey There!"';
            case "TYPE_MODULE": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_MODULE = $TYPE_BOOLEAN';
            case "TYPE_SIGN": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_SIGN = +';
            case "FUNCTION_RETURN": '$FUNCTION_DECLARATION y() = {\n&nbsp;&nbsp;&nbsp;&nbsp;$FUNCTION_RETURN 8\n}';
            case "READ_FUNCTION_NAME": '$VARIABLE_DECLARATION x = 3\n$READ_FUNCTION_NAME("x")';
            case "TYPE_DYNAMIC": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_DYNAMIC = nothing';
            case "PROPERTY_ACCESS_SIGN": '$VARIABLE_DECLARATION len = 8${PROPERTY_ACCESS_SIGN}type${PROPERTY_ACCESS_SIGN}length\n$PRINT_FUNCTION_NAME(len${PROPERTY_ACCESS_SIGN}type) //$TYPE_INT';
            case "TRUE_VALUE": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_BOOLEAN = $TRUE_VALUE $OR_SIGN $FALSE_VALUE\nif ($TRUE_VALUE) {}';
            case "FALSE_VALUE": '$VARIABLE_DECLARATION x $TYPE_DECL_OR_CAST $TYPE_BOOLEAN = $TRUE_VALUE $AND_SIGN $FALSE_VALUE\nif ($FALSE_VALUE) {}';
			case "EQUALS_SIGN": '$VARIABLE_DECLARATION x = $TRUE_VALUE $EQUALS_SIGN $TRUE_VALUE\nif (x $EQUALS_SIGN $TRUE_VALUE) {}';
			case "NOT_EQUALS_SIGN": '$VARIABLE_DECLARATION x = $TRUE_VALUE $NOT_EQUALS_SIGN $TRUE_VALUE\nif (x $NOT_EQUALS_SIGN $TRUE_VALUE) {}';
			case "LARGER_SIGN": '$VARIABLE_DECLARATION x = 5\nif (x $LARGER_SIGN 1) {}';
			case "SMALLER_SIGN": '$VARIABLE_DECLARATION x = -5\nif (x $SMALLER_SIGN 1) {}';
			case "LARGER_EQUALS_SIGN": '$VARIABLE_DECLARATION x = 5\nif (x $LARGER_EQUALS_SIGN 1 + 4) {}';
			case "SMALLER_EQUALS_SIGN": '$VARIABLE_DECLARATION x = 5\nif (x $SMALLER_EQUALS_SIGN -(1 + 4)) {}';
			case "XOR_SIGN": '$VARIABLE_DECLARATION x = $TRUE_VALUE $XOR_SIGN $TRUE_VALUE\nif (x $XOR_SIGN $TRUE_VALUE) {}';
			case "OR_SIGN": '$VARIABLE_DECLARATION x = $TRUE_VALUE $OR_SIGN $TRUE_VALUE\nif (x $OR_SIGN $TRUE_VALUE) {}';
			case "AND_SIGN": '$VARIABLE_DECLARATION x = $TRUE_VALUE $AND_SIGN $TRUE_VALUE\nif (x $AND_SIGN $TRUE_VALUE) {}';
            case _: "Unknown Keyword";
        }
    }

    static function snakeToTitleCase(str:String):String {
        var words = str.split("_");
        for (i in 0...words.length) {
            var word = words[i];
            if (word.length > 0) {
                var firstChar = word.charAt(0);
                var rest = word.substr(1);
                words[i] = firstChar.toUpperCase() + rest.toLowerCase();
            }
        }
        return words.join(" ");
    }
}