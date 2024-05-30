// Generated by Haxe 4.3.3
#ifndef INCLUDED_vision_ds__Image_PixelIterator
#define INCLUDED_vision_ds__Image_PixelIterator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(vision,ds,Pixel)
HX_DECLARE_CLASS3(vision,ds,_Image,PixelIterator)

namespace vision{
namespace ds{
namespace _Image{


class HXCPP_CLASS_ATTRIBUTES PixelIterator_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef PixelIterator_obj OBJ_;
		PixelIterator_obj();

	public:
		enum { _hx_ClassId = 0x29670be1 };

		void __construct( ::haxe::io::Bytes img);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="vision.ds._Image.PixelIterator")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"vision.ds._Image.PixelIterator"); }
		static ::hx::ObjectPtr< PixelIterator_obj > __new( ::haxe::io::Bytes img);
		static ::hx::ObjectPtr< PixelIterator_obj > __alloc(::hx::Ctx *_hx_ctx, ::haxe::io::Bytes img);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PixelIterator_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PixelIterator",74,12,73,74); }

		int i;
		 ::haxe::io::Bytes img;
		 ::vision::ds::Pixel next();
		::Dynamic next_dyn();

		bool hasNext();
		::Dynamic hasNext_dyn();

};

} // end namespace vision
} // end namespace ds
} // end namespace _Image

#endif /* INCLUDED_vision_ds__Image_PixelIterator */ 