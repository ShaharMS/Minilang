// Generated by Haxe 4.3.3
#include <hxcpp.h>

#ifndef INCLUDED_95f339a1d026d52c
#define INCLUDED_95f339a1d026d52c
#include "hxMath.h"
#endif
#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ArraySort
#include <haxe/ds/ArraySort.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_little_KeywordConfig
#include <little/KeywordConfig.h>
#endif
#ifndef INCLUDED_little_Little
#include <little/Little.h>
#endif
#ifndef INCLUDED_little_interpreter_InterpTokens
#include <little/interpreter/InterpTokens.h>
#endif
#ifndef INCLUDED_little_interpreter_memory_OperatorType
#include <little/interpreter/memory/OperatorType.h>
#endif
#ifndef INCLUDED_little_interpreter_memory_Operators
#include <little/interpreter/memory/Operators.h>
#endif
#ifndef INCLUDED_little_tools_TextTools
#include <little/tools/TextTools.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_18_new,"little.interpreter.memory.Operators","new",0x9aad1420,"little.interpreter.memory.Operators.new","little/interpreter/memory/Operators.hx",18,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_184_setPriority,"little.interpreter.memory.Operators","setPriority",0x6a8248e6,"little.interpreter.memory.Operators.setPriority","little/interpreter/memory/Operators.hx",184,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_86_setPriority,"little.interpreter.memory.Operators","setPriority",0x6a8248e6,"little.interpreter.memory.Operators.setPriority","little/interpreter/memory/Operators.hx",86,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_203_getPriority,"little.interpreter.memory.Operators","getPriority",0x601541da,"little.interpreter.memory.Operators.getPriority","little/interpreter/memory/Operators.hx",203,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_214_iterateByPriority,"little.interpreter.memory.Operators","iterateByPriority",0x98948ab5,"little.interpreter.memory.Operators.iterateByPriority","little/interpreter/memory/Operators.hx",214,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_218_iterateByPriority,"little.interpreter.memory.Operators","iterateByPriority",0x98948ab5,"little.interpreter.memory.Operators.iterateByPriority","little/interpreter/memory/Operators.hx",218,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_219_iterateByPriority,"little.interpreter.memory.Operators","iterateByPriority",0x98948ab5,"little.interpreter.memory.Operators.iterateByPriority","little/interpreter/memory/Operators.hx",219,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_212_iterateByPriority,"little.interpreter.memory.Operators","iterateByPriority",0x98948ab5,"little.interpreter.memory.Operators.iterateByPriority","little/interpreter/memory/Operators.hx",212,0x9c0a888f)
static const int _hx_array_data_4dd0c42e_22[] = {
	(int)0,
};
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_233_add,"little.interpreter.memory.Operators","add",0x9aa335e1,"little.interpreter.memory.Operators.add","little/interpreter/memory/Operators.hx",233,0x9c0a888f)
HX_LOCAL_STACK_FRAME(_hx_pos_19220bd4a5eab6d1_307_signPosToObject,"little.interpreter.memory.Operators","signPosToObject",0x8250fed1,"little.interpreter.memory.Operators.signPosToObject","little/interpreter/memory/Operators.hx",307,0x9c0a888f)
namespace little{
namespace interpreter{
namespace memory{

void Operators_obj::__construct(){
            	HX_GC_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_18_new)
HXLINE(  67)		this->lhsOnly =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  57)		this->rhsOnly =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  46)		this->standard =  ::haxe::ds::StringMap_obj::__alloc( HX_CTX );
HXLINE(  35)		this->priority =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
            	}

Dynamic Operators_obj::__CreateEmpty() { return new Operators_obj; }

void *Operators_obj::_hx_vtable = 0;

Dynamic Operators_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Operators_obj > _hx_result = new Operators_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Operators_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x2e96ce4a;
}

void Operators_obj::setPriority(::String op, ::little::interpreter::memory::OperatorType type,::String opPriority){
            		HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(2)
            		int _hx_run(int x,int y){
            			HX_GC_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_184_setPriority)
HXLINE( 184)			return (x - y);
            		}
            		HX_END_LOCAL_FUNC2(return)

            	HX_GC_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_86_setPriority)
HXLINE(  87)		 ::Dynamic obj =  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("side",97,8d,53,4c),type)
            			->setFixed(1,HX_("sign",3d,90,53,4c),op));
HXLINE(  88)		if ((opPriority == HX_("first",30,78,9d,00))) {
HXLINE(  89)			if (::hx::IsNull( this->priority->get(-1) )) {
HXLINE(  90)				::Array< ::Dynamic> v = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN(  90)				this->priority->set(-1,v);
            			}
HXLINE(  91)			( (::Array< ::Dynamic>)(this->priority->get(-1)) )->push(obj);
            		}
            		else {
HXLINE(  92)			if ((opPriority == HX_("last",56,0a,ad,47))) {
HXLINE(  93)				int i = -1;
HXLINE(  94)				{
HXLINE(  94)					 ::Dynamic key = this->priority->keys();
HXDLIN(  94)					while(( (bool)(key->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE(  94)						int key1 = ( (int)(key->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXLINE(  95)						if ((i < key1)) {
HXLINE(  96)							i = key1;
            						}
            					}
            				}
HXLINE(  97)				if (::hx::IsNull( this->priority->get((i + 1)) )) {
HXLINE(  98)					::Array< ::Dynamic> v1 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN(  98)					this->priority->set((i + 1),v1);
            				}
HXLINE(  99)				( (::Array< ::Dynamic>)(this->priority->get((i + 1))) )->push(obj);
            			}
            			else {
HXLINE( 100)				if ( ::EReg_obj::__alloc( HX_CTX ,HX_("[0-9]+",8f,d9,9f,23),HX_("",00,00,00,00))->match(opPriority)) {
HXLINE( 101)					 ::Dynamic p = ::Std_obj::parseInt(opPriority);
HXLINE( 102)					if (::hx::IsNull( this->priority->get(p) )) {
HXLINE( 103)						::Array< ::Dynamic> v2 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 103)						this->priority->set(( (int)(p) ),v2);
            					}
HXLINE( 104)					( (::Array< ::Dynamic>)(this->priority->get(p)) )->push(obj);
            				}
            				else {
HXLINE( 105)					bool _hx_tmp;
HXDLIN( 105)					bool _hx_tmp1;
HXDLIN( 105)					if (!(::StringTools_obj::startsWith(opPriority,HX_("before",7f,54,32,9a)))) {
HXLINE( 105)						_hx_tmp1 = ::StringTools_obj::startsWith(opPriority,HX_("after",1c,66,a2,1d));
            					}
            					else {
HXLINE( 105)						_hx_tmp1 = true;
            					}
HXDLIN( 105)					if (!(_hx_tmp1)) {
HXLINE( 105)						_hx_tmp = ::StringTools_obj::startsWith(opPriority,HX_("with",06,76,f8,4e));
            					}
            					else {
HXLINE( 105)						_hx_tmp = true;
            					}
HXDLIN( 105)					if (_hx_tmp) {
HXLINE( 106)						::String destinationOp;
HXDLIN( 106)						 ::little::interpreter::memory::OperatorType opSide;
HXLINE( 107)						::String signPos = ::StringTools_obj::trim(::little::tools::TextTools_obj::remove(::little::tools::TextTools_obj::remove(::little::tools::TextTools_obj::remove(opPriority,HX_("before",7f,54,32,9a)),HX_("after",1c,66,a2,1d)),HX_("with",06,76,f8,4e)));
HXLINE( 108)						if ((::little::tools::TextTools_obj::countOccurrencesOf(signPos,HX_("_",5f,00,00,00)) != 1)) {
HXLINE( 109)							destinationOp = ::StringTools_obj::replace(signPos,HX_("_",5f,00,00,00),HX_("",00,00,00,00));
HXLINE( 110)							opSide = ::little::interpreter::memory::OperatorType_obj::LHS_RHS_dyn();
            						}
            						else {
HXLINE( 111)							if (::StringTools_obj::startsWith(signPos,HX_("_",5f,00,00,00))) {
HXLINE( 112)								destinationOp = ::StringTools_obj::replace(signPos,HX_("_",5f,00,00,00),HX_("",00,00,00,00));
HXLINE( 113)								opSide = ::little::interpreter::memory::OperatorType_obj::LHS_ONLY_dyn();
            							}
            							else {
HXLINE( 115)								destinationOp = ::StringTools_obj::replace(signPos,HX_("_",5f,00,00,00),HX_("",00,00,00,00));
HXLINE( 116)								opSide = ::little::interpreter::memory::OperatorType_obj::RHS_ONLY_dyn();
            							}
            						}
HXLINE( 119)						{
HXLINE( 119)							::Dynamic map = this->priority;
HXDLIN( 119)							::Dynamic _g_map = map;
HXDLIN( 119)							 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN( 119)							while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 119)								int key2 = ( (int)(_g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 119)								::Array< ::Dynamic> _g_value = ( (::Array< ::Dynamic>)(::haxe::IMap_obj::get(_g_map,key2)) );
HXDLIN( 119)								int _g_key = key2;
HXDLIN( 119)								int key3 = _g_key;
HXDLIN( 119)								::Array< ::Dynamic> value = _g_value;
HXLINE( 120)								::Array< ::Dynamic> _g = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 120)								{
HXLINE( 120)									int _g1 = 0;
HXDLIN( 120)									::Array< ::Dynamic> _g2 = value;
HXDLIN( 120)									while((_g1 < _g2->length)){
HXLINE( 120)										 ::Dynamic v3 = _g2->__get(_g1);
HXDLIN( 120)										_g1 = (_g1 + 1);
HXDLIN( 120)										bool _hx_tmp2;
HXDLIN( 120)										if (::hx::IsPointerEq( v3->__Field(HX_("side",97,8d,53,4c),::hx::paccDynamic),opSide )) {
HXLINE( 120)											_hx_tmp2 = ::hx::IsEq( v3->__Field(HX_("sign",3d,90,53,4c),::hx::paccDynamic),destinationOp );
            										}
            										else {
HXLINE( 120)											_hx_tmp2 = false;
            										}
HXDLIN( 120)										if (_hx_tmp2) {
HXLINE( 120)											_g->push(v3);
            										}
            									}
            								}
HXDLIN( 120)								if ((_g->length > 0)) {
HXLINE( 121)									if (::StringTools_obj::startsWith(opPriority,HX_("before",7f,54,32,9a))) {
HXLINE( 122)										if (::hx::IsNull( this->priority->get((key3 - 1)) )) {
HXLINE( 123)											::Array< ::Dynamic> v4 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 123)											this->priority->set((key3 - 1),v4);
            										}
HXLINE( 124)										( (::Array< ::Dynamic>)(this->priority->get((key3 - 1))) )->push(obj);
            									}
            									else {
HXLINE( 125)										if (::StringTools_obj::startsWith(opPriority,HX_("after",1c,66,a2,1d))) {
HXLINE( 126)											if (::hx::IsNull( this->priority->get((key3 + 1)) )) {
HXLINE( 127)												::Array< ::Dynamic> v5 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 127)												this->priority->set((key3 + 1),v5);
            											}
HXLINE( 128)											( (::Array< ::Dynamic>)(this->priority->get((key3 + 1))) )->push(obj);
            										}
            										else {
HXLINE( 132)											( (::Array< ::Dynamic>)(this->priority->get(key3)) )->push(obj);
            										}
            									}
HXLINE( 134)									goto _hx_goto_2;
            								}
            							}
            							_hx_goto_2:;
            						}
            					}
            					else {
HXLINE( 137)						if (::StringTools_obj::startsWith(opPriority,HX_("between",c8,91,b3,66))) {
HXLINE( 138)							::String signPos1 = ::StringTools_obj::trim(::little::tools::TextTools_obj::remove(opPriority,HX_("between",c8,91,b3,66)));
HXLINE( 139)							::Array< ::String > _this = signPos1.split(HX_(" ",20,00,00,00));
HXDLIN( 139)							::Array< ::String > result = ::Array_obj< ::String >::__new(_this->length);
HXDLIN( 139)							{
HXLINE( 139)								int _g3 = 0;
HXDLIN( 139)								int _g4 = _this->length;
HXDLIN( 139)								while((_g3 < _g4)){
HXLINE( 139)									_g3 = (_g3 + 1);
HXDLIN( 139)									int i1 = (_g3 - 1);
HXDLIN( 139)									{
HXLINE( 139)										::String inValue = ::StringTools_obj::trim(( (::String)(_hx_array_unsafe_get(_this,i1)) ));
HXDLIN( 139)										result->__unsafe_set(i1,inValue);
            									}
            								}
            							}
HXDLIN( 139)							::Array< ::String > signs = result;
HXLINE( 140)							 ::Dynamic sign1Data = this->signPosToObject(signs->__get(0));
HXLINE( 141)							 ::Dynamic sign2Data = this->signPosToObject(signs->__get(1));
HXLINE( 143)							int sign1Level = -1;
HXDLIN( 143)							int sign2Level = -1;
HXLINE( 144)							{
HXLINE( 144)								::Dynamic map1 = this->priority;
HXDLIN( 144)								::Dynamic _g_map1 = map1;
HXDLIN( 144)								 ::Dynamic _g_keys1 = ::haxe::IMap_obj::keys(map1);
HXDLIN( 144)								while(( (bool)(_g_keys1->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 144)									int key4 = ( (int)(_g_keys1->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 144)									::Array< ::Dynamic> _g_value1 = ( (::Array< ::Dynamic>)(::haxe::IMap_obj::get(_g_map1,key4)) );
HXDLIN( 144)									int _g_key1 = key4;
HXDLIN( 144)									int key5 = _g_key1;
HXDLIN( 144)									::Array< ::Dynamic> value1 = _g_value1;
HXDLIN( 144)									{
HXLINE( 145)										::Array< ::Dynamic> _g5 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 145)										{
HXLINE( 145)											int _g6 = 0;
HXDLIN( 145)											::Array< ::Dynamic> _g7 = value1;
HXDLIN( 145)											while((_g6 < _g7->length)){
HXLINE( 145)												 ::Dynamic v6 = _g7->__get(_g6);
HXDLIN( 145)												_g6 = (_g6 + 1);
HXDLIN( 145)												bool _hx_tmp3;
HXDLIN( 145)												if (::hx::IsEq( v6->__Field(HX_("side",97,8d,53,4c),::hx::paccDynamic),sign1Data->__Field(HX_("side",97,8d,53,4c),::hx::paccDynamic) )) {
HXLINE( 145)													_hx_tmp3 = ::hx::IsEq( v6->__Field(HX_("sign",3d,90,53,4c),::hx::paccDynamic),sign1Data->__Field(HX_("sign",3d,90,53,4c),::hx::paccDynamic) );
            												}
            												else {
HXLINE( 145)													_hx_tmp3 = false;
            												}
HXDLIN( 145)												if (_hx_tmp3) {
HXLINE( 145)													_g5->push(v6);
            												}
            											}
            										}
HXDLIN( 145)										if ((_g5->length > 0)) {
HXLINE( 146)											sign1Level = key5;
            										}
HXLINE( 148)										::Array< ::Dynamic> _g8 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 148)										{
HXLINE( 148)											int _g9 = 0;
HXDLIN( 148)											::Array< ::Dynamic> _g10 = value1;
HXDLIN( 148)											while((_g9 < _g10->length)){
HXLINE( 148)												 ::Dynamic v7 = _g10->__get(_g9);
HXDLIN( 148)												_g9 = (_g9 + 1);
HXDLIN( 148)												bool _hx_tmp4;
HXDLIN( 148)												if (::hx::IsEq( v7->__Field(HX_("side",97,8d,53,4c),::hx::paccDynamic),sign2Data->__Field(HX_("side",97,8d,53,4c),::hx::paccDynamic) )) {
HXLINE( 148)													_hx_tmp4 = ::hx::IsEq( v7->__Field(HX_("sign",3d,90,53,4c),::hx::paccDynamic),sign2Data->__Field(HX_("sign",3d,90,53,4c),::hx::paccDynamic) );
            												}
            												else {
HXLINE( 148)													_hx_tmp4 = false;
            												}
HXDLIN( 148)												if (_hx_tmp4) {
HXLINE( 148)													_g8->push(v7);
            												}
            											}
            										}
HXDLIN( 148)										if ((_g8->length > 0)) {
HXLINE( 149)											sign2Level = key5;
            										}
            									}
            								}
            							}
HXLINE( 153)							bool _hx_tmp5;
HXDLIN( 153)							bool _hx_tmp6;
HXDLIN( 153)							bool _hx_tmp7;
HXDLIN( 153)							if ((sign1Level != -1)) {
HXLINE( 153)								_hx_tmp7 = (sign2Level != -1);
            							}
            							else {
HXLINE( 153)								_hx_tmp7 = false;
            							}
HXDLIN( 153)							if (_hx_tmp7) {
HXLINE( 153)								_hx_tmp6 = (sign1Level != sign2Level);
            							}
            							else {
HXLINE( 153)								_hx_tmp6 = false;
            							}
HXDLIN( 153)							if (_hx_tmp6) {
HXLINE( 153)								_hx_tmp5 = (::Math_obj::abs(( (Float)((sign1Level - sign2Level)) )) <= 2);
            							}
            							else {
HXLINE( 153)								_hx_tmp5 = false;
            							}
HXDLIN( 153)							if (_hx_tmp5) {
HXLINE( 154)								if ((::Math_obj::abs(( (Float)((sign1Level - sign2Level)) )) == 2)) {
HXLINE( 155)									int key6 = ::Std_obj::_hx_int((( (Float)((sign1Level + sign2Level)) ) / ( (Float)(2) )));
HXLINE( 156)									if (::hx::IsNull( this->priority->get(key6) )) {
HXLINE( 157)										::Array< ::Dynamic> v8 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 157)										this->priority->set(key6,v8);
            									}
HXLINE( 158)									( (::Array< ::Dynamic>)(this->priority->get(key6)) )->push(obj);
            								}
            								else {
HXLINE( 162)									int insert = ::Std_obj::_hx_int(::Math_obj::max(( (Float)(sign1Level) ),( (Float)(sign2Level) )));
HXLINE( 163)									 ::haxe::ds::IntMap newMap =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
HXLINE( 164)									{
HXLINE( 164)										::Dynamic map2 = this->priority;
HXDLIN( 164)										::Dynamic _g_map2 = map2;
HXDLIN( 164)										 ::Dynamic _g_keys2 = ::haxe::IMap_obj::keys(map2);
HXDLIN( 164)										while(( (bool)(_g_keys2->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 164)											int key7 = ( (int)(_g_keys2->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 164)											::Array< ::Dynamic> _g_value2 = ( (::Array< ::Dynamic>)(::haxe::IMap_obj::get(_g_map2,key7)) );
HXDLIN( 164)											int _g_key2 = key7;
HXDLIN( 164)											int k = _g_key2;
HXDLIN( 164)											::Array< ::Dynamic> v9 = _g_value2;
HXLINE( 165)											if ((k < insert)) {
HXLINE( 166)												newMap->set(k,v9);
            											}
            											else {
HXLINE( 168)												newMap->set((k + 1),v9);
            											}
            										}
            									}
HXLINE( 171)									{
HXLINE( 171)										::Array< ::Dynamic> v10 = ::Array_obj< ::Dynamic>::__new(1)->init(0,obj);
HXDLIN( 171)										newMap->set(insert,v10);
            									}
HXLINE( 172)									this->priority = newMap;
            								}
            							}
            						}
            					}
            				}
            			}
            		}
HXLINE( 182)		::Array< int > _g11 = ::Array_obj< int >::__new(0);
HXDLIN( 182)		{
HXLINE( 182)			 ::Dynamic x = this->priority->keys();
HXDLIN( 182)			while(( (bool)(x->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 182)				int x1 = ( (int)(x->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 182)				_g11->push(x1);
            			}
            		}
HXDLIN( 182)		::Array< int > a = _g11;
HXLINE( 183)		if ((a->length == 0)) {
HXLINE( 183)			return;
            		}
HXLINE( 184)		::haxe::ds::ArraySort_obj::sort(a, ::Dynamic(new _hx_Closure_0()));
HXLINE( 185)		int minimumKey = a->__get(0);
HXLINE( 186)		if ((minimumKey != 0)) {
HXLINE( 187)			int diff = (0 - minimumKey);
HXLINE( 188)			 ::haxe::ds::IntMap priorityCopy =  ::haxe::ds::IntMap_obj::__alloc( HX_CTX );
HXLINE( 189)			{
HXLINE( 189)				::Dynamic map3 = this->priority;
HXDLIN( 189)				::Dynamic _g_map3 = map3;
HXDLIN( 189)				 ::Dynamic _g_keys3 = ::haxe::IMap_obj::keys(map3);
HXDLIN( 189)				while(( (bool)(_g_keys3->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 189)					int key8 = ( (int)(_g_keys3->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 189)					::Array< ::Dynamic> _g_value3 = ( (::Array< ::Dynamic>)(::haxe::IMap_obj::get(_g_map3,key8)) );
HXDLIN( 189)					int _g_key3 = key8;
HXDLIN( 189)					int key9 = _g_key3;
HXDLIN( 189)					::Array< ::Dynamic> value2 = _g_value3;
HXLINE( 190)					priorityCopy->set((key9 + diff),value2);
            				}
            			}
HXLINE( 192)			this->priority = priorityCopy;
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC3(Operators_obj,setPriority,(void))

int Operators_obj::getPriority(::String op, ::little::interpreter::memory::OperatorType type){
            	HX_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_203_getPriority)
HXLINE( 204)		{
HXLINE( 204)			::Dynamic map = this->priority;
HXDLIN( 204)			::Dynamic _g_map = map;
HXDLIN( 204)			 ::Dynamic _g_keys = ::haxe::IMap_obj::keys(map);
HXDLIN( 204)			while(( (bool)(_g_keys->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 204)				int key = ( (int)(_g_keys->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 204)				::Array< ::Dynamic> _g_value = ( (::Array< ::Dynamic>)(::haxe::IMap_obj::get(_g_map,key)) );
HXDLIN( 204)				int _g_key = key;
HXDLIN( 204)				int index = _g_key;
HXDLIN( 204)				::Array< ::Dynamic> key1 = _g_value;
HXLINE( 205)				::Array< ::Dynamic> _g = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 205)				{
HXLINE( 205)					int _g1 = 0;
HXDLIN( 205)					::Array< ::Dynamic> _g2 = key1;
HXDLIN( 205)					while((_g1 < _g2->length)){
HXLINE( 205)						 ::Dynamic v = _g2->__get(_g1);
HXDLIN( 205)						_g1 = (_g1 + 1);
HXDLIN( 205)						bool _hx_tmp;
HXDLIN( 205)						if (::hx::IsEq( v->__Field(HX_("sign",3d,90,53,4c),::hx::paccDynamic),op )) {
HXLINE( 205)							_hx_tmp = ::hx::IsPointerEq( v->__Field(HX_("side",97,8d,53,4c),::hx::paccDynamic),type );
            						}
            						else {
HXLINE( 205)							_hx_tmp = false;
            						}
HXDLIN( 205)						if (_hx_tmp) {
HXLINE( 205)							_g->push(v);
            						}
            					}
            				}
HXDLIN( 205)				if ((_g->length > 0)) {
HXLINE( 205)					return index;
            				}
            			}
            		}
HXLINE( 206)		HX_STACK_DO_THROW(((HX_("Operator ",dc,f3,17,42) + op) + HX_(" not found",55,f3,a5,21)));
HXDLIN( 206)		return 0;
            	}


HX_DEFINE_DYNAMIC_FUNC2(Operators_obj,getPriority,return )

 ::Dynamic Operators_obj::iterateByPriority(){
            		HX_BEGIN_LOCAL_FUNC_S0(::hx::LocalFunc,_hx_Closure_0) HXARGC(2)
            		int _hx_run(int x,int y){
            			HX_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_214_iterateByPriority)
HXLINE( 214)			return (x - y);
            		}
            		HX_END_LOCAL_FUNC2(return)

            		HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_1,::Array< ::Dynamic>,b,::Array< int >,i) HXARGC(0)
            		::Array< ::Dynamic> _hx_run(){
            			HX_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_218_iterateByPriority)
HXLINE( 218)			return b->__get(i[0]++).StaticCast< ::Array< ::Dynamic> >();
            		}
            		HX_END_LOCAL_FUNC0(return)

            		HX_BEGIN_LOCAL_FUNC_S2(::hx::LocalFunc,_hx_Closure_2,::Array< ::Dynamic>,b,::Array< int >,i) HXARGC(0)
            		bool _hx_run(){
            			HX_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_219_iterateByPriority)
HXLINE( 219)			return (i->__get(0) < b->length);
            		}
            		HX_END_LOCAL_FUNC0(return)

            	HX_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_212_iterateByPriority)
HXLINE( 213)		::Array< int > _g = ::Array_obj< int >::__new(0);
HXDLIN( 213)		{
HXLINE( 213)			 ::Dynamic x = this->priority->keys();
HXDLIN( 213)			while(( (bool)(x->__Field(HX_("hasNext",6d,a5,46,18),::hx::paccDynamic)()) )){
HXLINE( 213)				int x1 = ( (int)(x->__Field(HX_("next",f3,84,02,49),::hx::paccDynamic)()) );
HXDLIN( 213)				_g->push(x1);
            			}
            		}
HXDLIN( 213)		::Array< int > a = _g;
HXLINE( 214)		::haxe::ds::ArraySort_obj::sort(a, ::Dynamic(new _hx_Closure_0()));
HXLINE( 215)		::Array< ::Dynamic> _g1 = ::Array_obj< ::Dynamic>::__new(0);
HXDLIN( 215)		{
HXLINE( 215)			int _g2 = 0;
HXDLIN( 215)			while((_g2 < a->length)){
HXLINE( 215)				int x2 = a->__get(_g2);
HXDLIN( 215)				_g2 = (_g2 + 1);
HXDLIN( 215)				_g1->push(this->priority->get(x2));
            			}
            		}
HXDLIN( 215)		::Array< ::Dynamic> b = _g1;
HXLINE( 216)		::Array< int > i = ::Array_obj< int >::fromData( _hx_array_data_4dd0c42e_22,1);
HXLINE( 217)		return  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("hasNext",6d,a5,46,18), ::Dynamic(new _hx_Closure_2(b,i)))
            			->setFixed(1,HX_("next",f3,84,02,49), ::Dynamic(new _hx_Closure_1(b,i))));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Operators_obj,iterateByPriority,return )

void Operators_obj::add(::String op, ::little::interpreter::memory::OperatorType operatorType,::String priority, ::Dynamic callback){
            	HX_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_233_add)
HXLINE( 234)		{
HXLINE( 234)			int _g = 0;
HXDLIN( 234)			int _g1 = op.length;
HXDLIN( 234)			while((_g < _g1)){
HXLINE( 234)				_g = (_g + 1);
HXDLIN( 234)				int i = (_g - 1);
HXLINE( 235)				::Array< ::String > _hx_tmp = ::little::KeywordConfig_obj::recognizedOperators;
HXDLIN( 235)				if (!(_hx_tmp->contains(op.charAt(i)))) {
HXLINE( 236)					::Array< ::String > _hx_tmp1 = ::little::KeywordConfig_obj::recognizedOperators;
HXDLIN( 236)					_hx_tmp1->push(op.charAt(i));
            				}
            			}
            		}
HXLINE( 237)		::little::Little_obj::keywords->RECOGNIZED_SIGNS->push(op);
HXLINE( 238)		switch((int)(operatorType->_hx_getIndex())){
            			case (int)0: {
HXLINE( 241)				this->standard->set(op,callback);
            			}
            			break;
            			case (int)1: {
HXLINE( 245)				this->lhsOnly->set(op,callback);
            			}
            			break;
            			case (int)2: {
HXLINE( 249)				this->rhsOnly->set(op,callback);
            			}
            			break;
            		}
HXLINE( 253)		this->setPriority(op,operatorType,priority);
            	}


HX_DEFINE_DYNAMIC_FUNC4(Operators_obj,add,(void))

 ::Dynamic Operators_obj::signPosToObject(::String signPos){
            	HX_STACKFRAME(&_hx_pos_19220bd4a5eab6d1_307_signPosToObject)
HXLINE( 308)		::String destinationOp;
HXDLIN( 308)		 ::little::interpreter::memory::OperatorType opSide;
HXLINE( 309)		if ((::little::tools::TextTools_obj::countOccurrencesOf(signPos,HX_("_",5f,00,00,00)) != 1)) {
HXLINE( 310)			destinationOp = ::StringTools_obj::replace(signPos,HX_("_",5f,00,00,00),HX_("",00,00,00,00));
HXLINE( 311)			opSide = ::little::interpreter::memory::OperatorType_obj::LHS_RHS_dyn();
            		}
            		else {
HXLINE( 312)			if (::StringTools_obj::startsWith(signPos,HX_("_",5f,00,00,00))) {
HXLINE( 313)				destinationOp = ::StringTools_obj::replace(signPos,HX_("_",5f,00,00,00),HX_("",00,00,00,00));
HXLINE( 314)				opSide = ::little::interpreter::memory::OperatorType_obj::LHS_ONLY_dyn();
            			}
            			else {
HXLINE( 316)				destinationOp = ::StringTools_obj::replace(signPos,HX_("_",5f,00,00,00),HX_("",00,00,00,00));
HXLINE( 317)				opSide = ::little::interpreter::memory::OperatorType_obj::RHS_ONLY_dyn();
            			}
            		}
HXLINE( 319)		return  ::Dynamic(::hx::Anon_obj::Create(2)
            			->setFixed(0,HX_("side",97,8d,53,4c),opSide)
            			->setFixed(1,HX_("sign",3d,90,53,4c),destinationOp));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Operators_obj,signPosToObject,return )


::hx::ObjectPtr< Operators_obj > Operators_obj::__new() {
	::hx::ObjectPtr< Operators_obj > __this = new Operators_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< Operators_obj > Operators_obj::__alloc(::hx::Ctx *_hx_ctx) {
	Operators_obj *__this = (Operators_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Operators_obj), true, "little.interpreter.memory.Operators"));
	*(void **)__this = Operators_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

Operators_obj::Operators_obj()
{
}

void Operators_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Operators);
	HX_MARK_MEMBER_NAME(priority,"priority");
	HX_MARK_MEMBER_NAME(standard,"standard");
	HX_MARK_MEMBER_NAME(rhsOnly,"rhsOnly");
	HX_MARK_MEMBER_NAME(lhsOnly,"lhsOnly");
	HX_MARK_END_CLASS();
}

void Operators_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(priority,"priority");
	HX_VISIT_MEMBER_NAME(standard,"standard");
	HX_VISIT_MEMBER_NAME(rhsOnly,"rhsOnly");
	HX_VISIT_MEMBER_NAME(lhsOnly,"lhsOnly");
}

::hx::Val Operators_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return ::hx::Val( add_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rhsOnly") ) { return ::hx::Val( rhsOnly ); }
		if (HX_FIELD_EQ(inName,"lhsOnly") ) { return ::hx::Val( lhsOnly ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"priority") ) { return ::hx::Val( priority ); }
		if (HX_FIELD_EQ(inName,"standard") ) { return ::hx::Val( standard ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setPriority") ) { return ::hx::Val( setPriority_dyn() ); }
		if (HX_FIELD_EQ(inName,"getPriority") ) { return ::hx::Val( getPriority_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"signPosToObject") ) { return ::hx::Val( signPosToObject_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"iterateByPriority") ) { return ::hx::Val( iterateByPriority_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Operators_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"rhsOnly") ) { rhsOnly=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lhsOnly") ) { lhsOnly=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"priority") ) { priority=inValue.Cast<  ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"standard") ) { standard=inValue.Cast<  ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Operators_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("priority",64,7b,3e,bb));
	outFields->push(HX_("standard",3d,37,78,ea));
	outFields->push(HX_("rhsOnly",09,d0,4c,85));
	outFields->push(HX_("lhsOnly",83,07,cc,8b));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Operators_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::haxe::ds::IntMap */ ,(int)offsetof(Operators_obj,priority),HX_("priority",64,7b,3e,bb)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(Operators_obj,standard),HX_("standard",3d,37,78,ea)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(Operators_obj,rhsOnly),HX_("rhsOnly",09,d0,4c,85)},
	{::hx::fsObject /*  ::haxe::ds::StringMap */ ,(int)offsetof(Operators_obj,lhsOnly),HX_("lhsOnly",83,07,cc,8b)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Operators_obj_sStaticStorageInfo = 0;
#endif

static ::String Operators_obj_sMemberFields[] = {
	HX_("priority",64,7b,3e,bb),
	HX_("standard",3d,37,78,ea),
	HX_("rhsOnly",09,d0,4c,85),
	HX_("lhsOnly",83,07,cc,8b),
	HX_("setPriority",26,45,9f,eb),
	HX_("getPriority",1a,3e,32,e1),
	HX_("iterateByPriority",f5,36,f4,5c),
	HX_("add",21,f2,49,00),
	HX_("signPosToObject",11,1b,41,95),
	::String(null()) };

::hx::Class Operators_obj::__mClass;

void Operators_obj::__register()
{
	Operators_obj _hx_dummy;
	Operators_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("little.interpreter.memory.Operators",2e,c4,d0,4d);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Operators_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Operators_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Operators_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Operators_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace little
} // end namespace interpreter
} // end namespace memory