// Generated by Haxe 4.3.4
#ifndef INCLUDED_vision_tools__ImageTools_NeighborsIterator
#define INCLUDED_vision_tools__ImageTools_NeighborsIterator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(vision,tools,_ImageTools,NeighborsIterator)

namespace vision{
namespace tools{
namespace _ImageTools{


class HXCPP_CLASS_ATTRIBUTES NeighborsIterator_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef NeighborsIterator_obj OBJ_;
		NeighborsIterator_obj();

	public:
		enum { _hx_ClassId = 0x30665943 };

		void __construct( ::haxe::io::Bytes image,int x,int y,int kernelSize,::hx::Null< bool >  __o_circular);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="vision.tools._ImageTools.NeighborsIterator")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"vision.tools._ImageTools.NeighborsIterator"); }
		static ::hx::ObjectPtr< NeighborsIterator_obj > __new( ::haxe::io::Bytes image,int x,int y,int kernelSize,::hx::Null< bool >  __o_circular);
		static ::hx::ObjectPtr< NeighborsIterator_obj > __alloc(::hx::Ctx *_hx_ctx, ::haxe::io::Bytes image,int x,int y,int kernelSize,::hx::Null< bool >  __o_circular);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~NeighborsIterator_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("NeighborsIterator",2f,4e,0e,1e); }

		int roundedDown;
		 ::haxe::io::Bytes image;
		int x;
		int y;
		int X;
		int Y;
		bool circular;
		int next();
		::Dynamic next_dyn();

		bool hasNext();
		::Dynamic hasNext_dyn();

};

} // end namespace vision
} // end namespace tools
} // end namespace _ImageTools

#endif /* INCLUDED_vision_tools__ImageTools_NeighborsIterator */ 