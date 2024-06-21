// Generated by Haxe 4.3.4
#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_little_KeywordConfig
#include <little/KeywordConfig.h>
#endif
#ifndef INCLUDED_little_Little
#include <little/Little.h>
#endif
#ifndef INCLUDED_little_interpreter_FieldDeclarationType
#include <little/interpreter/FieldDeclarationType.h>
#endif
#ifndef INCLUDED_little_interpreter_InterpTokens
#include <little/interpreter/InterpTokens.h>
#endif
#ifndef INCLUDED_little_interpreter_Runtime
#include <little/interpreter/Runtime.h>
#endif
#ifndef INCLUDED_little_interpreter_StdOut
#include <little/interpreter/StdOut.h>
#endif
#ifndef INCLUDED_little_tools_PrettyPrinter
#include <little/tools/PrettyPrinter.h>
#endif
#ifndef INCLUDED_little_tools_TextTools
#include <little/tools/TextTools.h>
#endif
#ifndef INCLUDED_little_tools__Layer_Layer_Impl_
#include <little/tools/_Layer/Layer_Impl_.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_bead45cc78a77e6d_15_new,"little.interpreter.Runtime","new",0x1833097e,"little.interpreter.Runtime.new","little/interpreter/Runtime.hx",15,0x90ac63b4)
HX_LOCAL_STACK_FRAME(_hx_pos_bead45cc78a77e6d_185_throwError,"little.interpreter.Runtime","throwError",0x1038bb64,"little.interpreter.Runtime.throwError","little/interpreter/Runtime.hx",185,0x90ac63b4)
HX_LOCAL_STACK_FRAME(_hx_pos_bead45cc78a77e6d_215_warn,"little.interpreter.Runtime","warn",0x1a652368,"little.interpreter.Runtime.warn","little/interpreter/Runtime.hx",215,0x90ac63b4)
HX_LOCAL_STACK_FRAME(_hx_pos_bead45cc78a77e6d_234_print,"little.interpreter.Runtime","print",0x018194cb,"little.interpreter.Runtime.print","little/interpreter/Runtime.hx",234,0x90ac63b4)
HX_LOCAL_STACK_FRAME(_hx_pos_bead45cc78a77e6d_243___default_broadcast,"little.interpreter.Runtime","__default_broadcast",0x7590d0c1,"little.interpreter.Runtime.__default_broadcast","little/interpreter/Runtime.hx",243,0x90ac63b4)
HX_LOCAL_STACK_FRAME(_hx_pos_bead45cc78a77e6d_251___default__hx___broadcast,"little.interpreter.Runtime","__default__hx___broadcast",0x45049351,"little.interpreter.Runtime.__default__hx___broadcast","little/interpreter/Runtime.hx",251,0x90ac63b4)
HX_LOCAL_STACK_FRAME(_hx_pos_bead45cc78a77e6d_258___print,"little.interpreter.Runtime","__print",0x435ed12b,"little.interpreter.Runtime.__print","little/interpreter/Runtime.hx",258,0x90ac63b4)
namespace little{
namespace interpreter{

void Runtime_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_bead45cc78a77e6d_15_new)
HXLINE( 177)		this->callStack = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 172)		this->_hx_stdout =  ::little::interpreter::StdOut_obj::__alloc( HX_CTX );
HXLINE( 167)		this->onTypeCast = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 159)		this->onFieldDeclared = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 149)		this->onConditionCalled = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 138)		this->onFunctionCalled = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 128)		this->onWriteValue = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 121)		this->onWarningPrinted = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 111)		this->onErrorThrown = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 102)		this->onTokenInterpreted = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  85)		this->onLineSplit = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  77)		this->onModuleChanged = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  67)		this->onLineChanged = ::Array_obj< ::Dynamic>::__new(0);
HXLINE(  55)		this->errorThrown = false;
HXLINE(  50)		this->exitCode = 0;
HXLINE(  37)		this->module = ::little::Little_obj::keywords->MAIN_MODULE_NAME;
HXLINE(  32)		this->currentToken = null();
HXLINE(  27)		this->linePart = 0;
HXLINE(  22)		this->line = 0;
            	}

Dynamic Runtime_obj::__CreateEmpty() { return new Runtime_obj; }

void *Runtime_obj::_hx_vtable = 0;

Dynamic Runtime_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Runtime_obj > _hx_result = new Runtime_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Runtime_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x46e9dbf4;
}

 ::little::interpreter::InterpTokens Runtime_obj::throwError( ::little::interpreter::InterpTokens token,::String __o_layer){
            		::String layer = __o_layer;
            		if (::hx::IsNull(__o_layer)) layer = HX_("Interpreter",9a,09,07,b9);
            	HX_STACKFRAME(&_hx_pos_bead45cc78a77e6d_185_throwError)
HXLINE( 187)		::String mod = this->module;
HXLINE( 190)		::String reason = ::Std_obj::string(token);
HXLINE( 187)		::String reason1 = ::little::tools::TextTools_obj::replaceLast(::little::tools::TextTools_obj::remove(reason,::Type_obj::enumConstructor(token)).substring(1,null()),HX_(")",29,00,00,00),HX_("",00,00,00,00));
HXLINE( 191)		::String content;
HXDLIN( 191)		if (::little::Little_obj::debug) {
HXLINE( 191)			content = (layer.toUpperCase() + HX_(": ",a6,32,00,00));
            		}
            		else {
HXLINE( 191)			content = HX_("",00,00,00,00);
            		}
HXLINE( 188)		::String content1 = (((((((HX_("",00,00,00,00) + content) + HX_("ERROR: Module ",46,5f,7a,f2)) + this->module) + HX_(", Line ",98,42,4b,f9)) + this->line) + HX_(":  ",ba,1e,2c,00)) + reason1);
HXLINE( 194)		 ::little::interpreter::StdOut fh = this->_hx_stdout;
HXDLIN( 194)		fh->output = (fh->output + ((HX_("\n",0a,00,00,00) + content1) + HX_("\n",0a,00,00,00)));
HXLINE( 195)		 ::little::interpreter::StdOut fh1 = this->_hx_stdout;
HXDLIN( 195)		::String fh2 = fh1->output;
HXDLIN( 195)		::Array< ::Dynamic> _this = this->callStack;
HXDLIN( 195)		::Array< ::String > result = ::Array_obj< ::String >::__new(_this->length);
HXDLIN( 195)		{
HXLINE( 195)			int _g = 0;
HXDLIN( 195)			int _g1 = _this->length;
HXDLIN( 195)			while((_g < _g1)){
HXLINE( 195)				_g = (_g + 1);
HXDLIN( 195)				int i = (_g - 1);
HXDLIN( 195)				{
HXLINE( 195)					 ::Dynamic obj = _hx_array_unsafe_get(_this,i);
HXDLIN( 195)					::String inValue = ( (::String)(((((((HX_("\tCalled from Module ",18,40,0b,68) + obj->__Field(HX_("module",ac,34,d3,c0),::hx::paccDynamic)) + HX_(", Line ",98,42,4b,f9)) + obj->__Field(HX_("line",f4,17,b3,47),::hx::paccDynamic)) + HX_(" (part ",c5,d7,4a,ee)) + obj->__Field(HX_("linePart",07,32,7b,87),::hx::paccDynamic)) + HX_("): ",0f,4f,1f,00))) );
HXDLIN( 195)					::String inValue1 = (inValue + ::little::tools::PrettyPrinter_obj::stringifyInterpreter(null(),obj->__Field(HX_("token",f9,82,2b,14),::hx::paccDynamic)));
HXDLIN( 195)					result->__unsafe_set(i,inValue1);
            				}
            			}
            		}
HXDLIN( 195)		fh1->output = (fh2 + result->join(HX_("\n",0a,00,00,00)));
HXLINE( 196)		this->_hx_stdout->stdoutTokens->push(token);
HXLINE( 198)		this->callStack->unshift( ::Dynamic(::hx::Anon_obj::Create(4)
            			->setFixed(0,HX_("linePart",07,32,7b,87),this->linePart)
            			->setFixed(1,HX_("module",ac,34,d3,c0),this->module)
            			->setFixed(2,HX_("token",f9,82,2b,14),token)
            			->setFixed(3,HX_("line",f4,17,b3,47),this->line)));
HXLINE( 200)		this->exitCode = ::little::tools::_Layer::Layer_Impl__obj::getIndexOf(layer);
HXLINE( 201)		this->errorToken = token;
HXLINE( 202)		this->errorThrown = true;
HXLINE( 203)		{
HXLINE( 203)			int _g2 = 0;
HXDLIN( 203)			::Array< ::Dynamic> _g3 = this->onErrorThrown;
HXDLIN( 203)			while((_g2 < _g3->length)){
HXLINE( 203)				 ::Dynamic func = _g3->__get(_g2);
HXDLIN( 203)				_g2 = (_g2 + 1);
HXDLIN( 203)				func(mod,this->line,reason1);
            			}
            		}
HXLINE( 205)		HX_STACK_DO_THROW(token);
HXDLIN( 205)		return null();
            	}


HX_DEFINE_DYNAMIC_FUNC2(Runtime_obj,throwError,return )

void Runtime_obj::warn( ::little::interpreter::InterpTokens token,::String __o_layer){
            		::String layer = __o_layer;
            		if (::hx::IsNull(__o_layer)) layer = HX_("Interpreter",9a,09,07,b9);
            	HX_STACKFRAME(&_hx_pos_bead45cc78a77e6d_215_warn)
HXLINE( 216)		this->callStack->unshift( ::Dynamic(::hx::Anon_obj::Create(4)
            			->setFixed(0,HX_("linePart",07,32,7b,87),this->linePart)
            			->setFixed(1,HX_("module",ac,34,d3,c0),this->module)
            			->setFixed(2,HX_("token",f9,82,2b,14),token)
            			->setFixed(3,HX_("line",f4,17,b3,47),this->line)));
HXLINE( 221)		::String reason = ::Std_obj::string(token);
HXLINE( 218)		::String reason1 = ::little::tools::TextTools_obj::replaceLast(::little::tools::TextTools_obj::remove(reason,::Type_obj::enumConstructor(token)).substring(1,null()),HX_(")",29,00,00,00),HX_("",00,00,00,00));
HXLINE( 222)		::String content;
HXDLIN( 222)		if (::little::Little_obj::debug) {
HXLINE( 222)			content = (layer.toUpperCase() + HX_(": ",a6,32,00,00));
            		}
            		else {
HXLINE( 222)			content = HX_("",00,00,00,00);
            		}
HXLINE( 219)		::String content1 = (((((((HX_("",00,00,00,00) + content) + HX_("WARNING: Module ",32,c2,ba,2f)) + this->module) + HX_(", Line ",98,42,4b,f9)) + this->line) + HX_(":  ",ba,1e,2c,00)) + reason1);
HXLINE( 225)		 ::little::interpreter::StdOut fh = this->_hx_stdout;
HXDLIN( 225)		fh->output = (fh->output + (HX_("\n",0a,00,00,00) + content1));
HXLINE( 226)		this->_hx_stdout->stdoutTokens->push(token);
HXLINE( 227)		{
HXLINE( 227)			int _g = 0;
HXDLIN( 227)			::Array< ::Dynamic> _g1 = this->onWarningPrinted;
HXDLIN( 227)			while((_g < _g1->length)){
HXLINE( 227)				 ::Dynamic func = _g1->__get(_g);
HXDLIN( 227)				_g = (_g + 1);
HXDLIN( 227)				func(this->module,this->line,reason1);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Runtime_obj,warn,(void))

void Runtime_obj::print(::String item){
            	HX_STACKFRAME(&_hx_pos_bead45cc78a77e6d_234_print)
HXLINE( 235)		 ::little::interpreter::StdOut fh = this->_hx_stdout;
HXDLIN( 235)		::String fh1 = fh->output;
HXDLIN( 235)		::String _hx_tmp;
HXDLIN( 235)		if (::little::Little_obj::debug) {
HXLINE( 235)			_hx_tmp = (HX_("Interpreter",9a,09,07,b9).toUpperCase() + HX_(": ",a6,32,00,00));
            		}
            		else {
HXLINE( 235)			_hx_tmp = HX_("",00,00,00,00);
            		}
HXDLIN( 235)		fh->output = (fh1 + (((((((HX_("\n",0a,00,00,00) + _hx_tmp) + HX_("Module ",d4,09,4c,c5)) + this->module) + HX_(", Line ",98,42,4b,f9)) + this->line) + HX_(":  ",ba,1e,2c,00)) + item));
HXLINE( 236)		this->_hx_stdout->stdoutTokens->push(::little::interpreter::InterpTokens_obj::Characters(item));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Runtime_obj,print,(void))

HX_BEGIN_DEFAULT_FUNC(__default_broadcast,Runtime_obj)
void _hx_run(::String item){
            	HX_STACKFRAME(&_hx_pos_bead45cc78a77e6d_243___default_broadcast)
HXLINE( 244)		 ::little::interpreter::StdOut fh = ( ( ::little::interpreter::Runtime)(__this) )->_hx_stdout;
HXDLIN( 244)		::String _hx_tmp;
HXDLIN( 244)		if (::little::Little_obj::debug) {
HXLINE( 244)			_hx_tmp = HX_("BROADCAST: ",c7,7f,45,e9);
            		}
            		else {
HXLINE( 244)			_hx_tmp = HX_("",00,00,00,00);
            		}
HXDLIN( 244)		fh->output = (fh->output + ((HX_("\n",0a,00,00,00) + _hx_tmp) + item));
HXLINE( 245)		( ( ::little::interpreter::Runtime)(__this) )->_hx_stdout->stdoutTokens->push(::little::interpreter::InterpTokens_obj::Characters(item));
            	}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default__hx___broadcast,Runtime_obj)
void _hx_run(::String item){
            	HX_STACKFRAME(&_hx_pos_bead45cc78a77e6d_251___default__hx___broadcast)
HXLINE( 252)		 ::little::interpreter::StdOut fh = ( ( ::little::interpreter::Runtime)(__this) )->_hx_stdout;
HXDLIN( 252)		::String _hx_tmp;
HXDLIN( 252)		if (::little::Little_obj::debug) {
HXLINE( 252)			_hx_tmp = HX_("BROADCAST: ",c7,7f,45,e9);
            		}
            		else {
HXLINE( 252)			_hx_tmp = HX_("",00,00,00,00);
            		}
HXDLIN( 252)		fh->output = (fh->output + ((HX_("\n",0a,00,00,00) + _hx_tmp) + item));
            	}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

void Runtime_obj::_hx___print(::String item, ::little::interpreter::InterpTokens representativeToken){
            	HX_STACKFRAME(&_hx_pos_bead45cc78a77e6d_258___print)
HXLINE( 259)		 ::little::interpreter::StdOut fh = this->_hx_stdout;
HXDLIN( 259)		::String fh1 = fh->output;
HXDLIN( 259)		::String _hx_tmp;
HXDLIN( 259)		if (::little::Little_obj::debug) {
HXLINE( 259)			_hx_tmp = (HX_("Interpreter",9a,09,07,b9).toUpperCase() + HX_(": ",a6,32,00,00));
            		}
            		else {
HXLINE( 259)			_hx_tmp = HX_("",00,00,00,00);
            		}
HXDLIN( 259)		fh->output = (fh1 + (((((((HX_("\n",0a,00,00,00) + _hx_tmp) + HX_("Module ",d4,09,4c,c5)) + this->module) + HX_(", Line ",98,42,4b,f9)) + this->line) + HX_(":  ",ba,1e,2c,00)) + item));
HXLINE( 260)		this->_hx_stdout->stdoutTokens->push(representativeToken);
            	}


HX_DEFINE_DYNAMIC_FUNC2(Runtime_obj,_hx___print,(void))


void Runtime_obj::__alloc_dynamic_functions(::hx::Ctx *_hx_ctx,Runtime_obj *_hx_obj) {
	if (!_hx_obj->_hx___broadcast.mPtr) _hx_obj->_hx___broadcast = new __default__hx___broadcast(_hx_obj);
	if (!_hx_obj->broadcast.mPtr) _hx_obj->broadcast = new __default_broadcast(_hx_obj);
}
::hx::ObjectPtr< Runtime_obj > Runtime_obj::__new() {
	::hx::ObjectPtr< Runtime_obj > __this = new Runtime_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< Runtime_obj > Runtime_obj::__alloc(::hx::Ctx *_hx_ctx) {
	Runtime_obj *__this = (Runtime_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Runtime_obj), true, "little.interpreter.Runtime"));
	*(void **)__this = Runtime_obj::_hx_vtable;
	little::interpreter::Runtime_obj::__alloc_dynamic_functions(_hx_ctx,__this);
	__this->__construct();
	return __this;
}

Runtime_obj::Runtime_obj()
{
	_hx___broadcast = new __default__hx___broadcast(this);
	broadcast = new __default_broadcast(this);
}

void Runtime_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Runtime);
	HX_MARK_MEMBER_NAME(line,"line");
	HX_MARK_MEMBER_NAME(linePart,"linePart");
	HX_MARK_MEMBER_NAME(currentToken,"currentToken");
	HX_MARK_MEMBER_NAME(module,"module");
	HX_MARK_MEMBER_NAME(previousToken,"previousToken");
	HX_MARK_MEMBER_NAME(exitCode,"exitCode");
	HX_MARK_MEMBER_NAME(errorThrown,"errorThrown");
	HX_MARK_MEMBER_NAME(errorToken,"errorToken");
	HX_MARK_MEMBER_NAME(onLineChanged,"onLineChanged");
	HX_MARK_MEMBER_NAME(onModuleChanged,"onModuleChanged");
	HX_MARK_MEMBER_NAME(onLineSplit,"onLineSplit");
	HX_MARK_MEMBER_NAME(onTokenInterpreted,"onTokenInterpreted");
	HX_MARK_MEMBER_NAME(onErrorThrown,"onErrorThrown");
	HX_MARK_MEMBER_NAME(onWarningPrinted,"onWarningPrinted");
	HX_MARK_MEMBER_NAME(onWriteValue,"onWriteValue");
	HX_MARK_MEMBER_NAME(onFunctionCalled,"onFunctionCalled");
	HX_MARK_MEMBER_NAME(onConditionCalled,"onConditionCalled");
	HX_MARK_MEMBER_NAME(onFieldDeclared,"onFieldDeclared");
	HX_MARK_MEMBER_NAME(onTypeCast,"onTypeCast");
	HX_MARK_MEMBER_NAME(_hx_stdout,"stdout");
	HX_MARK_MEMBER_NAME(callStack,"callStack");
	HX_MARK_MEMBER_NAME(broadcast,"broadcast");
	HX_MARK_MEMBER_NAME(_hx___broadcast,"__broadcast");
	HX_MARK_END_CLASS();
}

void Runtime_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(line,"line");
	HX_VISIT_MEMBER_NAME(linePart,"linePart");
	HX_VISIT_MEMBER_NAME(currentToken,"currentToken");
	HX_VISIT_MEMBER_NAME(module,"module");
	HX_VISIT_MEMBER_NAME(previousToken,"previousToken");
	HX_VISIT_MEMBER_NAME(exitCode,"exitCode");
	HX_VISIT_MEMBER_NAME(errorThrown,"errorThrown");
	HX_VISIT_MEMBER_NAME(errorToken,"errorToken");
	HX_VISIT_MEMBER_NAME(onLineChanged,"onLineChanged");
	HX_VISIT_MEMBER_NAME(onModuleChanged,"onModuleChanged");
	HX_VISIT_MEMBER_NAME(onLineSplit,"onLineSplit");
	HX_VISIT_MEMBER_NAME(onTokenInterpreted,"onTokenInterpreted");
	HX_VISIT_MEMBER_NAME(onErrorThrown,"onErrorThrown");
	HX_VISIT_MEMBER_NAME(onWarningPrinted,"onWarningPrinted");
	HX_VISIT_MEMBER_NAME(onWriteValue,"onWriteValue");
	HX_VISIT_MEMBER_NAME(onFunctionCalled,"onFunctionCalled");
	HX_VISIT_MEMBER_NAME(onConditionCalled,"onConditionCalled");
	HX_VISIT_MEMBER_NAME(onFieldDeclared,"onFieldDeclared");
	HX_VISIT_MEMBER_NAME(onTypeCast,"onTypeCast");
	HX_VISIT_MEMBER_NAME(_hx_stdout,"stdout");
	HX_VISIT_MEMBER_NAME(callStack,"callStack");
	HX_VISIT_MEMBER_NAME(broadcast,"broadcast");
	HX_VISIT_MEMBER_NAME(_hx___broadcast,"__broadcast");
}

::hx::Val Runtime_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"line") ) { return ::hx::Val( line ); }
		if (HX_FIELD_EQ(inName,"warn") ) { return ::hx::Val( warn_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return ::hx::Val( print_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"module") ) { return ::hx::Val( module ); }
		if (HX_FIELD_EQ(inName,"stdout") ) { return ::hx::Val( _hx_stdout ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"__print") ) { return ::hx::Val( _hx___print_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"linePart") ) { return ::hx::Val( linePart ); }
		if (HX_FIELD_EQ(inName,"exitCode") ) { return ::hx::Val( exitCode ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"callStack") ) { return ::hx::Val( callStack ); }
		if (HX_FIELD_EQ(inName,"broadcast") ) { return ::hx::Val( broadcast ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"errorToken") ) { return ::hx::Val( errorToken ); }
		if (HX_FIELD_EQ(inName,"onTypeCast") ) { return ::hx::Val( onTypeCast ); }
		if (HX_FIELD_EQ(inName,"throwError") ) { return ::hx::Val( throwError_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"errorThrown") ) { return ::hx::Val( errorThrown ); }
		if (HX_FIELD_EQ(inName,"onLineSplit") ) { return ::hx::Val( onLineSplit ); }
		if (HX_FIELD_EQ(inName,"__broadcast") ) { return ::hx::Val( _hx___broadcast ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentToken") ) { return ::hx::Val( currentToken ); }
		if (HX_FIELD_EQ(inName,"onWriteValue") ) { return ::hx::Val( onWriteValue ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"previousToken") ) { return ::hx::Val( previousToken ); }
		if (HX_FIELD_EQ(inName,"onLineChanged") ) { return ::hx::Val( onLineChanged ); }
		if (HX_FIELD_EQ(inName,"onErrorThrown") ) { return ::hx::Val( onErrorThrown ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onModuleChanged") ) { return ::hx::Val( onModuleChanged ); }
		if (HX_FIELD_EQ(inName,"onFieldDeclared") ) { return ::hx::Val( onFieldDeclared ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onWarningPrinted") ) { return ::hx::Val( onWarningPrinted ); }
		if (HX_FIELD_EQ(inName,"onFunctionCalled") ) { return ::hx::Val( onFunctionCalled ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onConditionCalled") ) { return ::hx::Val( onConditionCalled ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onTokenInterpreted") ) { return ::hx::Val( onTokenInterpreted ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Runtime_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"line") ) { line=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"module") ) { module=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stdout") ) { _hx_stdout=inValue.Cast<  ::little::interpreter::StdOut >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"linePart") ) { linePart=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"exitCode") ) { exitCode=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"callStack") ) { callStack=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"broadcast") ) { broadcast=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"errorToken") ) { errorToken=inValue.Cast<  ::little::interpreter::InterpTokens >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onTypeCast") ) { onTypeCast=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"errorThrown") ) { errorThrown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onLineSplit") ) { onLineSplit=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__broadcast") ) { _hx___broadcast=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentToken") ) { currentToken=inValue.Cast<  ::little::interpreter::InterpTokens >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onWriteValue") ) { onWriteValue=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"previousToken") ) { previousToken=inValue.Cast<  ::little::interpreter::InterpTokens >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onLineChanged") ) { onLineChanged=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onErrorThrown") ) { onErrorThrown=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onModuleChanged") ) { onModuleChanged=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onFieldDeclared") ) { onFieldDeclared=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onWarningPrinted") ) { onWarningPrinted=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onFunctionCalled") ) { onFunctionCalled=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onConditionCalled") ) { onConditionCalled=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onTokenInterpreted") ) { onTokenInterpreted=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Runtime_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("line",f4,17,b3,47));
	outFields->push(HX_("linePart",07,32,7b,87));
	outFields->push(HX_("currentToken",00,68,37,5b));
	outFields->push(HX_("module",ac,34,d3,c0));
	outFields->push(HX_("previousToken",42,8f,1f,3b));
	outFields->push(HX_("exitCode",6b,bb,88,01));
	outFields->push(HX_("errorThrown",70,6a,2e,7d));
	outFields->push(HX_("errorToken",11,72,2f,89));
	outFields->push(HX_("onLineChanged",81,84,0a,6e));
	outFields->push(HX_("onModuleChanged",09,39,42,1e));
	outFields->push(HX_("onLineSplit",27,d1,ac,ea));
	outFields->push(HX_("onTokenInterpreted",72,12,ac,0f));
	outFields->push(HX_("onErrorThrown",91,87,18,e0));
	outFields->push(HX_("onWarningPrinted",4f,74,bf,76));
	outFields->push(HX_("onWriteValue",11,1c,be,9e));
	outFields->push(HX_("onFunctionCalled",34,e3,fa,d1));
	outFields->push(HX_("onConditionCalled",19,1a,7a,85));
	outFields->push(HX_("onFieldDeclared",35,5b,a0,45));
	outFields->push(HX_("onTypeCast",d8,f6,3b,8c));
	outFields->push(HX_("stdout",cb,bf,f3,07));
	outFields->push(HX_("callStack",ca,c1,4a,10));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Runtime_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(Runtime_obj,line),HX_("line",f4,17,b3,47)},
	{::hx::fsInt,(int)offsetof(Runtime_obj,linePart),HX_("linePart",07,32,7b,87)},
	{::hx::fsObject /*  ::little::interpreter::InterpTokens */ ,(int)offsetof(Runtime_obj,currentToken),HX_("currentToken",00,68,37,5b)},
	{::hx::fsString,(int)offsetof(Runtime_obj,module),HX_("module",ac,34,d3,c0)},
	{::hx::fsObject /*  ::little::interpreter::InterpTokens */ ,(int)offsetof(Runtime_obj,previousToken),HX_("previousToken",42,8f,1f,3b)},
	{::hx::fsInt,(int)offsetof(Runtime_obj,exitCode),HX_("exitCode",6b,bb,88,01)},
	{::hx::fsBool,(int)offsetof(Runtime_obj,errorThrown),HX_("errorThrown",70,6a,2e,7d)},
	{::hx::fsObject /*  ::little::interpreter::InterpTokens */ ,(int)offsetof(Runtime_obj,errorToken),HX_("errorToken",11,72,2f,89)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onLineChanged),HX_("onLineChanged",81,84,0a,6e)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onModuleChanged),HX_("onModuleChanged",09,39,42,1e)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onLineSplit),HX_("onLineSplit",27,d1,ac,ea)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onTokenInterpreted),HX_("onTokenInterpreted",72,12,ac,0f)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onErrorThrown),HX_("onErrorThrown",91,87,18,e0)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onWarningPrinted),HX_("onWarningPrinted",4f,74,bf,76)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onWriteValue),HX_("onWriteValue",11,1c,be,9e)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onFunctionCalled),HX_("onFunctionCalled",34,e3,fa,d1)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onConditionCalled),HX_("onConditionCalled",19,1a,7a,85)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onFieldDeclared),HX_("onFieldDeclared",35,5b,a0,45)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,onTypeCast),HX_("onTypeCast",d8,f6,3b,8c)},
	{::hx::fsObject /*  ::little::interpreter::StdOut */ ,(int)offsetof(Runtime_obj,_hx_stdout),HX_("stdout",cb,bf,f3,07)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(Runtime_obj,callStack),HX_("callStack",ca,c1,4a,10)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Runtime_obj,broadcast),HX_("broadcast",01,a3,19,df)},
	{::hx::fsObject /*  ::Dynamic */ ,(int)offsetof(Runtime_obj,_hx___broadcast),HX_("__broadcast",e1,eb,45,0d)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Runtime_obj_sStaticStorageInfo = 0;
#endif

static ::String Runtime_obj_sMemberFields[] = {
	HX_("line",f4,17,b3,47),
	HX_("linePart",07,32,7b,87),
	HX_("currentToken",00,68,37,5b),
	HX_("module",ac,34,d3,c0),
	HX_("previousToken",42,8f,1f,3b),
	HX_("exitCode",6b,bb,88,01),
	HX_("errorThrown",70,6a,2e,7d),
	HX_("errorToken",11,72,2f,89),
	HX_("onLineChanged",81,84,0a,6e),
	HX_("onModuleChanged",09,39,42,1e),
	HX_("onLineSplit",27,d1,ac,ea),
	HX_("onTokenInterpreted",72,12,ac,0f),
	HX_("onErrorThrown",91,87,18,e0),
	HX_("onWarningPrinted",4f,74,bf,76),
	HX_("onWriteValue",11,1c,be,9e),
	HX_("onFunctionCalled",34,e3,fa,d1),
	HX_("onConditionCalled",19,1a,7a,85),
	HX_("onFieldDeclared",35,5b,a0,45),
	HX_("onTypeCast",d8,f6,3b,8c),
	HX_("stdout",cb,bf,f3,07),
	HX_("callStack",ca,c1,4a,10),
	HX_("throwError",c2,74,e5,ee),
	HX_("warn",46,62,f2,4e),
	HX_("print",2d,58,8b,c8),
	HX_("broadcast",01,a3,19,df),
	HX_("__broadcast",e1,eb,45,0d),
	HX_("__print",0d,b1,e9,32),
	::String(null()) };

::hx::Class Runtime_obj::__mClass;

void Runtime_obj::__register()
{
	Runtime_obj _hx_dummy;
	Runtime_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("little.interpreter.Runtime",8c,32,dd,a1);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Runtime_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Runtime_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Runtime_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Runtime_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace little
} // end namespace interpreter