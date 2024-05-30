// Generated by Haxe 4.3.3
#include <hxcpp.h>

#ifndef INCLUDED_little_interpreter_InterpTokens
#include <little/interpreter/InterpTokens.h>
#endif
#ifndef INCLUDED_little_interpreter_StdOut
#include <little/interpreter/StdOut.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_8c448cc15578c930_5_new,"little.interpreter.StdOut","new",0xee4dd4e9,"little.interpreter.StdOut.new","little/interpreter/StdOut.hx",5,0xda0abce5)
HX_LOCAL_STACK_FRAME(_hx_pos_8c448cc15578c930_22_reset,"little.interpreter.StdOut","reset",0xcab34298,"little.interpreter.StdOut.reset","little/interpreter/StdOut.hx",22,0xda0abce5)
namespace little{
namespace interpreter{

void StdOut_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_8c448cc15578c930_5_new)
HXLINE(  16)		this->stdoutTokens = ::Array_obj< ::Dynamic>::__new();
HXLINE(  10)		this->output = HX_("",00,00,00,00);
            	}

Dynamic StdOut_obj::__CreateEmpty() { return new StdOut_obj; }

void *StdOut_obj::_hx_vtable = 0;

Dynamic StdOut_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< StdOut_obj > _hx_result = new StdOut_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool StdOut_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x015ca80f;
}

void StdOut_obj::reset(){
            	HX_STACKFRAME(&_hx_pos_8c448cc15578c930_22_reset)
HXLINE(  23)		this->output = HX_("",00,00,00,00);
HXLINE(  24)		this->stdoutTokens = ::Array_obj< ::Dynamic>::__new();
            	}


HX_DEFINE_DYNAMIC_FUNC0(StdOut_obj,reset,(void))


::hx::ObjectPtr< StdOut_obj > StdOut_obj::__new() {
	::hx::ObjectPtr< StdOut_obj > __this = new StdOut_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< StdOut_obj > StdOut_obj::__alloc(::hx::Ctx *_hx_ctx) {
	StdOut_obj *__this = (StdOut_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(StdOut_obj), true, "little.interpreter.StdOut"));
	*(void **)__this = StdOut_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

StdOut_obj::StdOut_obj()
{
}

void StdOut_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StdOut);
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(stdoutTokens,"stdoutTokens");
	HX_MARK_END_CLASS();
}

void StdOut_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(output,"output");
	HX_VISIT_MEMBER_NAME(stdoutTokens,"stdoutTokens");
}

::hx::Val StdOut_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return ::hx::Val( reset_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { return ::hx::Val( output ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"stdoutTokens") ) { return ::hx::Val( stdoutTokens ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val StdOut_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"stdoutTokens") ) { stdoutTokens=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StdOut_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("output",01,0f,81,0c));
	outFields->push(HX_("stdoutTokens",85,b5,cd,43));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo StdOut_obj_sMemberStorageInfo[] = {
	{::hx::fsString,(int)offsetof(StdOut_obj,output),HX_("output",01,0f,81,0c)},
	{::hx::fsObject /* ::Array< ::Dynamic> */ ,(int)offsetof(StdOut_obj,stdoutTokens),HX_("stdoutTokens",85,b5,cd,43)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *StdOut_obj_sStaticStorageInfo = 0;
#endif

static ::String StdOut_obj_sMemberFields[] = {
	HX_("output",01,0f,81,0c),
	HX_("stdoutTokens",85,b5,cd,43),
	HX_("reset",cf,49,c8,e6),
	::String(null()) };

::hx::Class StdOut_obj::__mClass;

void StdOut_obj::__register()
{
	StdOut_obj _hx_dummy;
	StdOut_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("little.interpreter.StdOut",77,2c,dd,76);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(StdOut_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< StdOut_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = StdOut_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = StdOut_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace little
} // end namespace interpreter