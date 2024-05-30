// Generated by Haxe 4.3.3
#ifndef INCLUDED_vision_ds__PixelFormat_PixelFormat_Impl_
#define INCLUDED_vision_ds__PixelFormat_PixelFormat_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(vision,ds,_PixelFormat,PixelFormat_Impl_)

namespace vision{
namespace ds{
namespace _PixelFormat{


class HXCPP_CLASS_ATTRIBUTES PixelFormat_Impl__obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef PixelFormat_Impl__obj OBJ_;
		PixelFormat_Impl__obj();

	public:
		enum { _hx_ClassId = 0x1f8a6be4 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="vision.ds._PixelFormat.PixelFormat_Impl_")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"vision.ds._PixelFormat.PixelFormat_Impl_"); }

		inline static ::hx::ObjectPtr< PixelFormat_Impl__obj > __new() {
			::hx::ObjectPtr< PixelFormat_Impl__obj > __this = new PixelFormat_Impl__obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< PixelFormat_Impl__obj > __alloc(::hx::Ctx *_hx_ctx) {
			PixelFormat_Impl__obj *__this = (PixelFormat_Impl__obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(PixelFormat_Impl__obj), false, "vision.ds._PixelFormat.PixelFormat_Impl_"));
			*(void **)__this = PixelFormat_Impl__obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~PixelFormat_Impl__obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("PixelFormat_Impl_",9d,12,98,cd); }

		static void __boot();
		static int ARGB;
		static int RGBA;
		static int ABGR;
		static int BGRA;
		static int RGB;
		static int BGR;
		static  ::haxe::io::Bytes convertPixelFormat( ::haxe::io::Bytes bytes,int from, ::Dynamic to);
		static ::Dynamic convertPixelFormat_dyn();

};

} // end namespace vision
} // end namespace ds
} // end namespace _PixelFormat

#endif /* INCLUDED_vision_ds__PixelFormat_PixelFormat_Impl_ */ 