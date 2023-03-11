package little.interpreter;

import little.tools.PrettyPrinter;
import little.tools.Layer;
import little.parser.Tokens.ParserTokens;



@:structInit
/**
	Represents a function/variable in memory. contains usage fields.
**/
class MemoryObject {
    public var value:ParserTokens = NullValue;
    @:optional public var props:Map<String, MemoryObject> = [];
    @:optional public var params:Array<ParserTokens> = [];
    @:optional public var type:ParserTokens = null;
    @:optional public var external:Bool = false;

    public function new(?value:ParserTokens, ?props:Map<String, MemoryObject>, ?params:Array<ParserTokens>, ?type:ParserTokens, ?external:Bool) {
        this.value = value;
        this.props = props;
        this.params = params;
        this.type = type;
        this.external = external;
    }


    public function useFunction(parameters:ParserTokens):ParserTokens {
        if (parameters.getName() != "PartArray") return ErrorMessage('Incorrect parameter group format, given group format: ${parameters.getName()}, expectedFormat: ${PartArray}');


        var given:Array<ParserTokens> = [];
        if (parameters.getParameters()[0].length != 0) {
            var currentParam:Array<ParserTokens> = [];
            var _params:Array<ParserTokens> = parameters.getParameters()[0];
            for (value in _params) {
                switch value {
                    case SplitLine | SetLine(_): {
                        given.push(Expression(currentParam.copy(), null));
                        currentParam = [];
                    }
                    case _: currentParam.push(value);
                }
            }
            if (currentParam.length != 0) given.push(Expression(currentParam.copy(), null));
        }

        if (given.length != params.length) return ErrorMessage('Incorrect number of parameters, expected: ${params.length}, given: ${given.length}');

        if (external) {
            if (value.getName() != "External") return ErrorMessage('Undefined external function');
            return (value.getParameters()[0] : Array<ParserTokens> -> ParserTokens)(given);
        } else {
            var paramsDecl = [];
            for (i in 0...given.length) {
                paramsDecl.push(Write([params[i]], given[i], null));
            }
            paramsDecl.push(SplitLine);

            var body = null;
            if (value.getName() == "Block") {
                body = value.getParameters()[0];
                body = paramsDecl.concat(body);

            } else {
                paramsDecl.push(value);
                body = paramsDecl;
            }
            trace(PrettyPrinter.printParserAst(body));
            return Interpreter.runTokens(body, null, null, null);
        }
    }
}