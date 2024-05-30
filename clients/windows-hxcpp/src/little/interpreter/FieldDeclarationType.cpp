// Generated by Haxe 4.3.3
#include <hxcpp.h>

#ifndef INCLUDED_little_interpreter_FieldDeclarationType
#include <little/interpreter/FieldDeclarationType.h>
#endif
namespace little{
namespace interpreter{

::little::interpreter::FieldDeclarationType FieldDeclarationType_obj::CLASS;

::little::interpreter::FieldDeclarationType FieldDeclarationType_obj::CONDITION;

::little::interpreter::FieldDeclarationType FieldDeclarationType_obj::FUNCTION;

::little::interpreter::FieldDeclarationType FieldDeclarationType_obj::OPERATOR;

::little::interpreter::FieldDeclarationType FieldDeclarationType_obj::VARIABLE;

bool FieldDeclarationType_obj::__GetStatic(const ::String &inName, ::Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("CLASS",18,b0,46,c6)) { outValue = FieldDeclarationType_obj::CLASS; return true; }
	if (inName==HX_("CONDITION",7b,59,8c,f7)) { outValue = FieldDeclarationType_obj::CONDITION; return true; }
	if (inName==HX_("FUNCTION",18,3b,d8,6d)) { outValue = FieldDeclarationType_obj::FUNCTION; return true; }
	if (inName==HX_("OPERATOR",a4,ab,f8,9d)) { outValue = FieldDeclarationType_obj::OPERATOR; return true; }
	if (inName==HX_("VARIABLE",3c,a2,92,c2)) { outValue = FieldDeclarationType_obj::VARIABLE; return true; }
	return super::__GetStatic(inName, outValue, inCallProp);
}

HX_DEFINE_CREATE_ENUM(FieldDeclarationType_obj)

int FieldDeclarationType_obj::__FindIndex(::String inName)
{
	if (inName==HX_("CLASS",18,b0,46,c6)) return 3;
	if (inName==HX_("CONDITION",7b,59,8c,f7)) return 2;
	if (inName==HX_("FUNCTION",18,3b,d8,6d)) return 1;
	if (inName==HX_("OPERATOR",a4,ab,f8,9d)) return 4;
	if (inName==HX_("VARIABLE",3c,a2,92,c2)) return 0;
	return super::__FindIndex(inName);
}

int FieldDeclarationType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_("CLASS",18,b0,46,c6)) return 0;
	if (inName==HX_("CONDITION",7b,59,8c,f7)) return 0;
	if (inName==HX_("FUNCTION",18,3b,d8,6d)) return 0;
	if (inName==HX_("OPERATOR",a4,ab,f8,9d)) return 0;
	if (inName==HX_("VARIABLE",3c,a2,92,c2)) return 0;
	return super::__FindArgCount(inName);
}

::hx::Val FieldDeclarationType_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	if (inName==HX_("CLASS",18,b0,46,c6)) return CLASS;
	if (inName==HX_("CONDITION",7b,59,8c,f7)) return CONDITION;
	if (inName==HX_("FUNCTION",18,3b,d8,6d)) return FUNCTION;
	if (inName==HX_("OPERATOR",a4,ab,f8,9d)) return OPERATOR;
	if (inName==HX_("VARIABLE",3c,a2,92,c2)) return VARIABLE;
	return super::__Field(inName,inCallProp);
}

static ::String FieldDeclarationType_obj_sStaticFields[] = {
	HX_("VARIABLE",3c,a2,92,c2),
	HX_("FUNCTION",18,3b,d8,6d),
	HX_("CONDITION",7b,59,8c,f7),
	HX_("CLASS",18,b0,46,c6),
	HX_("OPERATOR",a4,ab,f8,9d),
	::String(null())
};

::hx::Class FieldDeclarationType_obj::__mClass;

Dynamic __Create_FieldDeclarationType_obj() { return new FieldDeclarationType_obj; }

void FieldDeclarationType_obj::__register()
{

::hx::Static(__mClass) = ::hx::_hx_RegisterClass(HX_("little.interpreter.FieldDeclarationType",06,1f,39,84), ::hx::TCanCast< FieldDeclarationType_obj >,FieldDeclarationType_obj_sStaticFields,0,
	&__Create_FieldDeclarationType_obj, &__Create,
	&super::__SGetClass(), &CreateFieldDeclarationType_obj, 0
#ifdef HXCPP_VISIT_ALLOCS
    , 0
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
	__mClass->mGetStaticField = &FieldDeclarationType_obj::__GetStatic;
}

void FieldDeclarationType_obj::__boot()
{
CLASS = ::hx::CreateConstEnum< FieldDeclarationType_obj >(HX_("CLASS",18,b0,46,c6),3);
CONDITION = ::hx::CreateConstEnum< FieldDeclarationType_obj >(HX_("CONDITION",7b,59,8c,f7),2);
FUNCTION = ::hx::CreateConstEnum< FieldDeclarationType_obj >(HX_("FUNCTION",18,3b,d8,6d),1);
OPERATOR = ::hx::CreateConstEnum< FieldDeclarationType_obj >(HX_("OPERATOR",a4,ab,f8,9d),4);
VARIABLE = ::hx::CreateConstEnum< FieldDeclarationType_obj >(HX_("VARIABLE",3c,a2,92,c2),0);
}


} // end namespace little
} // end namespace interpreter