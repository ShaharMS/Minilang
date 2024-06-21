// Generated by Haxe 4.3.4
#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_Resource
#include <haxe/Resource.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_little_Little
#include <little/Little.h>
#endif
#ifndef INCLUDED_little_interpreter_InterpTokens
#include <little/interpreter/InterpTokens.h>
#endif
#ifndef INCLUDED_little_interpreter_Interpreter
#include <little/interpreter/Interpreter.h>
#endif
#ifndef INCLUDED_little_interpreter_Runtime
#include <little/interpreter/Runtime.h>
#endif
#ifndef INCLUDED_little_interpreter_StdOut
#include <little/interpreter/StdOut.h>
#endif
#ifndef INCLUDED_little_lexer_Lexer
#include <little/lexer/Lexer.h>
#endif
#ifndef INCLUDED_little_lexer_LexerTokens
#include <little/lexer/LexerTokens.h>
#endif
#ifndef INCLUDED_little_parser_Parser
#include <little/parser/Parser.h>
#endif
#ifndef INCLUDED_little_parser_ParserTokens
#include <little/parser/ParserTokens.h>
#endif
#ifndef INCLUDED_little_tools_PrettyPrinter
#include <little/tools/PrettyPrinter.h>
#endif
#ifndef INCLUDED_little_tools_TextTools
#include <little/tools/TextTools.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_63_main,"Main","main",0xed0e206e,"Main.main","Main.hx",63,0x087e5c05)

void Main_obj::__construct() { }

Dynamic Main_obj::__CreateEmpty() { return new Main_obj; }

void *Main_obj::_hx_vtable = 0;

Dynamic Main_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Main_obj > _hx_result = new Main_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Main_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x07825a7d;
}

void Main_obj::main(){
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_63_main)
HXDLIN(  63)		try {
            			HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE(  64)			::String preDefInput = null();
HXLINE(  66)			::Sys_obj::print((((HX_("Little Interpreter v",e6,9f,53,99) + ::little::Little_obj::version) + HX_("\n\n",c0,08,00,00)) + HX_("Type \"ml!\" for multi-line mode, \"default!\" for single-line mode, or \"ast!\" for abstract syntax tree mode.\nPress `Ctrl`+`C` to exit at any time.\n\n",51,1a,b0,a7)));
HXLINE(  71)			::Sys_obj::print(HX_("If You're new to the language, type \"printSample!\" to print a file of sample code.\n\n",65,60,74,62));
HXLINE(  72)			::Sys_obj::println(HX_("-------------SINGLE-LINE MODE--------------\n",93,82,2d,7c));
HXLINE(  73)			while(true){
HXLINE(  74)				if (::hx::IsNull( preDefInput )) {
HXLINE(  75)					::Sys_obj::print(HX_("  >> ",e0,a5,28,82));
            				}
HXLINE(  76)				::String input;
HXDLIN(  76)				::String tmp = preDefInput;
HXDLIN(  76)				if (::hx::IsNotNull( tmp )) {
HXLINE(  76)					input = tmp;
            				}
            				else {
HXLINE(  76)					input = ::Sys_obj::_hx_stdin()->readLine();
            				}
HXLINE(  77)				if ((input == HX_("ml!",e2,13,53,00))) {
HXLINE(  78)					::Sys_obj::command(HX_("cls",aa,7d,4b,00),null());
HXLINE(  79)					::Sys_obj::print(HX_("--------------MULTI-LINE MODE--------------\n",8f,9d,0d,23));
HXLINE(  80)					::Sys_obj::println(HX_("Commands:\n\t- \"run!\": runs the code\n\t- \"clear!\": resets the code\n\t- \"clearLine!\": deletes the last line\n",bf,65,1b,b0));
HXLINE(  81)					::Sys_obj::println(HX_("Command \"printSample!\" is temporarily disabled. return to single-line or ast mode to use it again\n",20,15,ac,5b));
HXLINE(  82)					::String code = HX_("",00,00,00,00);
HXLINE(  83)					while(true){
HXLINE(  84)						::Sys_obj::print(HX_("  >> ",e0,a5,28,82));
HXLINE(  85)						::String input1 = ::Sys_obj::_hx_stdin()->readLine();
HXLINE(  86)						if ((input1 == HX_("run!",76,7a,b3,4b))) {
HXLINE(  87)							::little::Little_obj::run(code,true);
HXLINE(  88)							::Sys_obj::println(HX_("Output:",f9,39,bd,b1));
HXLINE(  89)							::Sys_obj::println((::little::Little_obj::runtime->_hx_stdout->output + HX_("\n",0a,00,00,00)));
HXLINE(  90)							::little::Little_obj::reset();
HXLINE(  91)							::Sys_obj::print((::little::tools::TextTools_obj::replace(::little::tools::TextTools_obj::replaceFirst(code,HX_("\n",0a,00,00,00),HX_("  >> ",e0,a5,28,82)),HX_("\n",0a,00,00,00),HX_("\n  >> ",96,41,ba,81)) + HX_("\n",0a,00,00,00)));
            						}
            						else {
HXLINE(  92)							if ((input1 == HX_("default!",40,d0,99,af))) {
HXLINE(  93)								::Sys_obj::command(HX_("cls",aa,7d,4b,00),null());
HXLINE(  94)								::Sys_obj::println(HX_("-------------SINGLE-LINE MODE--------------\n",93,82,2d,7c));
HXLINE(  95)								goto _hx_goto_1;
            							}
            							else {
HXLINE(  96)								if ((input1 == HX_("ast!",9f,5a,75,40))) {
HXLINE(  97)									::Sys_obj::command(HX_("cls",aa,7d,4b,00),null());
HXLINE(  98)									preDefInput = HX_("ast!",9f,5a,75,40);
HXLINE(  99)									goto _hx_goto_1;
            								}
            								else {
HXLINE( 100)									if ((input1 == HX_("clear!",f4,e9,a7,07))) {
HXLINE( 101)										code = HX_("",00,00,00,00);
HXLINE( 102)										::Sys_obj::command(HX_("cls",aa,7d,4b,00),null());
HXLINE( 103)										::Sys_obj::println(HX_("--------------MULTI-LINE MODE--------------\n",8f,9d,0d,23));
            									}
            									else {
HXLINE( 104)										if ((input1 == HX_("clearLine!",e0,1c,0c,4a))) {
HXLINE( 105)											::Sys_obj::command(HX_("cls",aa,7d,4b,00),null());
HXLINE( 106)											::Sys_obj::println(HX_("--------------MULTI-LINE MODE--------------\n",8f,9d,0d,23));
HXLINE( 107)											::Sys_obj::print((::little::tools::TextTools_obj::replace(::little::tools::TextTools_obj::replaceFirst(code,HX_("\n",0a,00,00,00),HX_("  >> ",e0,a5,28,82)),HX_("\n",0a,00,00,00),HX_("\n  >> ",96,41,ba,81)) + HX_("\n",0a,00,00,00)));
HXLINE( 108)											code = code.split(HX_("\n",0a,00,00,00))->slice(0,-1)->join(HX_("\n",0a,00,00,00));
            										}
            										else {
HXLINE( 110)											code = (code + (HX_("\n",0a,00,00,00) + input1));
            										}
            									}
            								}
            							}
            						}
            					}
            					_hx_goto_1:;
HXLINE( 113)					if ((preDefInput == HX_("ast!",9f,5a,75,40))) {
HXLINE( 114)						continue;
            					}
            				}
            				else {
HXLINE( 115)					if ((input == HX_("ast!",9f,5a,75,40))) {
HXLINE( 116)						::String _hx_tmp;
HXDLIN( 116)						if ((preDefInput == HX_("ast!",9f,5a,75,40))) {
HXLINE( 116)							_hx_tmp = HX_("",00,00,00,00);
            						}
            						else {
HXLINE( 116)							_hx_tmp = HX_("\n",0a,00,00,00);
            						}
HXDLIN( 116)						::Sys_obj::println(((HX_("",00,00,00,00) + _hx_tmp) + HX_("---------ABSTRACT SYNTAX TREE MODE---------\n",16,2e,48,b2)));
HXLINE( 117)						while(true){
HXLINE( 118)							::Sys_obj::print(HX_("  >> ",e0,a5,28,82));
HXLINE( 119)							::String input2 = ::Sys_obj::_hx_stdin()->readLine();
HXLINE( 120)							if ((input2 == HX_("default!",40,d0,99,af))) {
HXLINE( 121)								::Sys_obj::println(HX_("\n-------------SINGLE-LINE MODE--------------\n",9d,d1,62,d4));
HXLINE( 122)								goto _hx_goto_2;
            							}
            							else {
HXLINE( 123)								if ((input2 == HX_("printSample!",0a,a4,08,e5))) {
HXLINE( 124)									::Sys_obj::println(HX_("\n---------------SAMPLE CODE-----------------\n",3d,0c,4e,83));
HXLINE( 125)									::Sys_obj::println(::haxe::Resource_obj::getString(HX_("sample",2a,60,4a,1d)));
HXLINE( 126)									::Sys_obj::println(HX_("\n---------ABSTRACT SYNTAX TREE MODE---------\n",20,7d,7d,0a));
HXLINE( 127)									continue;
            								}
            							}
HXLINE( 129)							try {
            								HX_STACK_CATCHABLE( ::Dynamic, 0);
HXLINE( 130)								::Sys_obj::println(HX_("Output:",f9,39,bd,b1));
HXLINE( 131)								 ::Dynamic array = ::little::parser::Parser_obj::parse;
HXDLIN( 131)								::Sys_obj::println((::little::tools::PrettyPrinter_obj::printInterpreterAst(::little::interpreter::Interpreter_obj::convert(( (::Array< ::Dynamic>)(array(::little::lexer::Lexer_obj::lex(input2))) )),null()) + HX_("\n",0a,00,00,00)));
            							} catch( ::Dynamic _hx_e) {
            								if (_hx_e.IsClass<  ::Dynamic >() ){
            									HX_STACK_BEGIN_CATCH
            									 ::Dynamic _g = _hx_e;
            								}
            								else {
            									HX_STACK_DO_THROW(_hx_e);
            								}
            							}
            						}
            						_hx_goto_2:;
            					}
            					else {
HXLINE( 134)						if ((input == HX_("printSample!",0a,a4,08,e5))) {
HXLINE( 135)							::Sys_obj::println(HX_("\n---------------SAMPLE CODE-----------------\n",3d,0c,4e,83));
HXLINE( 136)							::Sys_obj::println(::haxe::Resource_obj::getString(HX_("sample",2a,60,4a,1d)));
HXLINE( 137)							::Sys_obj::println(HX_("\n-------------SINGLE-LINE MODE--------------\n",9d,d1,62,d4));
            						}
            						else {
HXLINE( 139)							::little::Little_obj::run(input,true);
HXLINE( 140)							::Sys_obj::println(HX_("Output:",f9,39,bd,b1));
HXLINE( 141)							::Sys_obj::println((::little::Little_obj::runtime->_hx_stdout->output + HX_("\n",0a,00,00,00)));
HXLINE( 142)							::little::Little_obj::reset();
            						}
            					}
            				}
HXLINE( 144)				preDefInput = null();
            			}
            		} catch( ::Dynamic _hx_e) {
            			if (_hx_e.IsClass<  ::Dynamic >() ){
            				HX_STACK_BEGIN_CATCH
            				 ::Dynamic _g1 = _hx_e;
HXLINE( 148)				::Sys_obj::println(HX_("\n\nExiting...",ca,5a,95,32));
HXLINE( 149)				::Sys_obj::exit(0);
            			}
            			else {
            				HX_STACK_DO_THROW(_hx_e);
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

bool Main_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { outValue = main_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *Main_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *Main_obj_sStaticStorageInfo = 0;
#endif

::hx::Class Main_obj::__mClass;

static ::String Main_obj_sStaticFields[] = {
	HX_("main",39,38,56,48),
	::String(null())
};

void Main_obj::__register()
{
	Main_obj _hx_dummy;
	Main_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Main",59,64,2f,33);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Main_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Main_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< Main_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Main_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Main_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}
