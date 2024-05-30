// Generated by Haxe 4.3.3
#ifndef INCLUDED_little_tools_TextTools
#define INCLUDED_little_tools_TextTools

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)
HX_DECLARE_CLASS2(little,tools,TextTools)
HX_DECLARE_CLASS3(little,tools,_TextTools,MultilangFonts)

namespace little{
namespace tools{


class HXCPP_CLASS_ATTRIBUTES TextTools_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef TextTools_obj OBJ_;
		TextTools_obj();

	public:
		enum { _hx_ClassId = 0x35935509 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="little.tools.TextTools")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,false,"little.tools.TextTools"); }

		inline static ::hx::ObjectPtr< TextTools_obj > __new() {
			::hx::ObjectPtr< TextTools_obj > __this = new TextTools_obj();
			__this->__construct();
			return __this;
		}

		inline static ::hx::ObjectPtr< TextTools_obj > __alloc(::hx::Ctx *_hx_ctx) {
			TextTools_obj *__this = (TextTools_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(TextTools_obj), false, "little.tools.TextTools"));
			*(void **)__this = TextTools_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~TextTools_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("TextTools",0e,02,ef,4e); }

		static void __boot();
		static  ::little::tools::_TextTools::MultilangFonts fonts;
		static ::String replaceLast(::String string,::String replace,::String by);
		static ::Dynamic replaceLast_dyn();

		static ::String replaceIfLast(::String string,::String replace,::String by);
		static ::Dynamic replaceIfLast_dyn();

		static ::String replaceFirst(::String string,::String replace,::String by);
		static ::Dynamic replaceFirst_dyn();

		static ::Array< ::String > splitOnFirst(::String string,::String delimiter);
		static ::Dynamic splitOnFirst_dyn();

		static ::Array< ::String > splitOnLast(::String string,::String delimiter);
		static ::Dynamic splitOnLast_dyn();

		static ::Array< ::String > splitOnParagraph(::String text);
		static ::Dynamic splitOnParagraph_dyn();

		static ::String filter(::String text, ::Dynamic filter);
		static ::Dynamic filter_dyn();

		static ::Array< ::Dynamic> indexesOf(::String string,::String sub);
		static ::Dynamic indexesOf_dyn();

		static ::Array< ::Dynamic> indexesOfSubs(::String string,::Array< ::String > subs);
		static ::Dynamic indexesOfSubs_dyn();

		static ::Array< ::Dynamic> indexesFromArray(::String string,::Array< ::String > subs);
		static ::Dynamic indexesFromArray_dyn();

		static ::Array< ::Dynamic> indexesFromEReg(::String string, ::EReg ereg);
		static ::Dynamic indexesFromEReg_dyn();

		static ::String multiply(::String string,int times);
		static ::Dynamic multiply_dyn();

		static ::String subtract(::String string,::String by);
		static ::Dynamic subtract_dyn();

		static ::String loremIpsum(::hx::Null< int >  paragraphs,::hx::Null< int >  length);
		static ::Dynamic loremIpsum_dyn();

		static ::Array< ::String > sortByLength(::Array< ::String > array);
		static ::Dynamic sortByLength_dyn();

		static ::Array< Float > sortByValue(::Array< Float > array);
		static ::Dynamic sortByValue_dyn();

		static ::Array< int > sortByIntValue(::Array< int > array);
		static ::Dynamic sortByIntValue_dyn();

		static int getLineIndexOfChar(::String string,int index);
		static ::Dynamic getLineIndexOfChar_dyn();

		static int countOccurrencesOf(::String string,::String sub);
		static ::Dynamic countOccurrencesOf_dyn();

		static bool contains(::String string,::String contains);
		static ::Dynamic contains_dyn();

		static ::String remove(::String string,::String sub);
		static ::Dynamic remove_dyn();

		static ::String replace(::String string,::String replace,::String with);
		static ::Dynamic replace_dyn();

		static ::String reverse(::String string);
		static ::Dynamic reverse_dyn();

		static ::String insert(::String string,::String substring,int at);
		static ::Dynamic insert_dyn();

		static bool parseBool(::String string);
		static ::Dynamic parseBool_dyn();

		static bool containsAny(::String string,::Array< ::String > from);
		static ::Dynamic containsAny_dyn();

		static ::String loremIpsumText;
};

} // end namespace little
} // end namespace tools

#endif /* INCLUDED_little_tools_TextTools */ 