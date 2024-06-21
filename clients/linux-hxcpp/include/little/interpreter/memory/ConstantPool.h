// Generated by Haxe 4.3.4
#ifndef INCLUDED_little_interpreter_memory_ConstantPool
#define INCLUDED_little_interpreter_memory_ConstantPool

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(little,interpreter,InterpTokens)
HX_DECLARE_CLASS3(little,interpreter,memory,ConstantPool)
HX_DECLARE_CLASS3(little,interpreter,memory,Memory)

namespace little{
namespace interpreter{
namespace memory{


class HXCPP_CLASS_ATTRIBUTES ConstantPool_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef ConstantPool_obj OBJ_;
		ConstantPool_obj();

	public:
		enum { _hx_ClassId = 0x601f2761 };

		void __construct( ::little::interpreter::memory::Memory memory);
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="little.interpreter.memory.ConstantPool")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"little.interpreter.memory.ConstantPool"); }
		static ::hx::ObjectPtr< ConstantPool_obj > __new( ::little::interpreter::memory::Memory memory);
		static ::hx::ObjectPtr< ConstantPool_obj > __alloc(::hx::Ctx *_hx_ctx, ::little::interpreter::memory::Memory memory);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~ConstantPool_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("ConstantPool",80,3c,6c,1f); }

		int capacity;
		int _hx_NULL;
		int FALSE;
		int TRUE;
		int ZERO;
		int INT;
		int FLOAT;
		int BOOL;
		int DYNAMIC;
		int TYPE;
		int UNKNOWN;
		int ERROR_TOKEN;
		int EXTERN;
		int EMPTY_STRING;
		int get( ::little::interpreter::InterpTokens token);
		::Dynamic get_dyn();

		 ::little::interpreter::InterpTokens getFromPointer(int pointer);
		::Dynamic getFromPointer_dyn();

		bool hasPointer(int pointer);
		::Dynamic hasPointer_dyn();

		bool hasType(::String typeName);
		::Dynamic hasType_dyn();

		int getType(::String typeName);
		::Dynamic getType_dyn();

};

} // end namespace little
} // end namespace interpreter
} // end namespace memory

#endif /* INCLUDED_little_interpreter_memory_ConstantPool */ 