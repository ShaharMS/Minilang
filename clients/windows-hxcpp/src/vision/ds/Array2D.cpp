// Generated by Haxe 4.3.3
#include <hxcpp.h>

#ifndef INCLUDED_38344beec7696400
#define INCLUDED_38344beec7696400
#include "cpp/Int64.h"
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_iterators_ArrayIterator
#include <haxe/iterators/ArrayIterator.h>
#endif
#ifndef INCLUDED_vision_ds_Array2D
#include <vision/ds/Array2D.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_51_new,"vision.ds.Array2D","new",0xea11c664,"vision.ds.Array2D.new","vision/ds/Array2D.hx",51,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_67_get,"vision.ds.Array2D","get",0xea0c769a,"vision.ds.Array2D.get","vision/ds/Array2D.hx",67,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_74_set,"vision.ds.Array2D","set",0xea1591a6,"vision.ds.Array2D.set","vision/ds/Array2D.hx",74,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_83_setMultiple,"vision.ds.Array2D","setMultiple",0x805745d6,"vision.ds.Array2D.setMultiple","vision/ds/Array2D.hx",83,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_92_row,"vision.ds.Array2D","row",0xea14d81e,"vision.ds.Array2D.row","vision/ds/Array2D.hx",92,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_99_column,"vision.ds.Array2D","column",0x6e0ff352,"vision.ds.Array2D.column","vision/ds/Array2D.hx",99,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_110_iterator,"vision.ds.Array2D","iterator",0xa0ee056a,"vision.ds.Array2D.iterator","vision/ds/Array2D.hx",110,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_118_fill,"vision.ds.Array2D","fill",0xe0351bff,"vision.ds.Array2D.fill","vision/ds/Array2D.hx",118,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_128_clone,"vision.ds.Array2D","clone",0x960d9261,"vision.ds.Array2D.clone","vision/ds/Array2D.hx",128,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_137_toString,"vision.ds.Array2D","toString",0x45c28c28,"vision.ds.Array2D.toString","vision/ds/Array2D.hx",137,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_159_get_length,"vision.ds.Array2D","get_length",0x65e5972b,"vision.ds.Array2D.get_length","vision/ds/Array2D.hx",159,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_162_set_length,"vision.ds.Array2D","set_length",0x6963359f,"vision.ds.Array2D.set_length","vision/ds/Array2D.hx",162,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_167_set_width,"vision.ds.Array2D","set_width",0x8d4d4f6d,"vision.ds.Array2D.set_width","vision/ds/Array2D.hx",167,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_172_set_height,"vision.ds.Array2D","set_height",0xcca7a8a0,"vision.ds.Array2D.set_height","vision/ds/Array2D.hx",172,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_178_get_item,"vision.ds.Array2D","get_item",0xd2ce3c18,"vision.ds.Array2D.get_item","vision/ds/Array2D.hx",178,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_182_set_item,"vision.ds.Array2D","set_item",0x812b958c,"vision.ds.Array2D.set_item","vision/ds/Array2D.hx",182,0x234dd02c)
HX_LOCAL_STACK_FRAME(_hx_pos_54eb3c9fef85e8a2_185_to2DArray,"vision.ds.Array2D","to2DArray",0x0665f950,"vision.ds.Array2D.to2DArray","vision/ds/Array2D.hx",185,0x234dd02c)
namespace vision{
namespace ds{

void Array2D_obj::__construct(int width,int height, ::Dynamic fillWith){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_51_new)
HXLINE(  52)		this->width = width;
HXLINE(  53)		this->height = height;
HXLINE(  55)		this->inner = ::cpp::VirtualArray_obj::__new();
HXLINE(  56)		this->inner->resize((width * height));
HXLINE(  57)		if (::hx::IsNotNull( fillWith )) {
HXLINE(  58)			int _g = 0;
HXDLIN(  58)			int _g1 = this->inner->get_length();
HXDLIN(  58)			while((_g < _g1)){
HXLINE(  58)				_g = (_g + 1);
HXDLIN(  58)				int i = (_g - 1);
HXLINE(  59)				this->inner->set(i,fillWith);
            			}
            		}
            	}

Dynamic Array2D_obj::__CreateEmpty() { return new Array2D_obj; }

void *Array2D_obj::_hx_vtable = 0;

Dynamic Array2D_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Array2D_obj > _hx_result = new Array2D_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool Array2D_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4bbde2f4;
}

 ::Dynamic Array2D_obj::get(int x,int y){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_67_get)
HXDLIN(  67)		return this->inner->__get(((y * this->width) + x));
            	}


HX_DEFINE_DYNAMIC_FUNC2(Array2D_obj,get,return )

 ::Dynamic Array2D_obj::set(int x,int y, ::Dynamic val){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_74_set)
HXDLIN(  74)		return (this->inner->set((x + (y * this->width)),val));
            	}


HX_DEFINE_DYNAMIC_FUNC3(Array2D_obj,set,return )

void Array2D_obj::setMultiple(::Array< ::cpp::Int64 > points, ::Dynamic val){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_83_setMultiple)
HXDLIN(  83)		int _g = 0;
HXDLIN(  83)		while((_g < points->length)){
HXDLIN(  83)			::cpp::Int64 p = points->__get(_g);
HXDLIN(  83)			_g = (_g + 1);
HXLINE(  84)			{
HXLINE(  84)				int x = _hx_int64_high(p);
HXDLIN(  84)				int y = _hx_int64_low(p);
HXDLIN(  84)				this->inner->set((x + (y * this->width)),val);
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC2(Array2D_obj,setMultiple,(void))

::cpp::VirtualArray Array2D_obj::row(int y){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_92_row)
HXDLIN(  92)		::cpp::VirtualArray _g = ::cpp::VirtualArray_obj::__new(0);
HXDLIN(  92)		{
HXDLIN(  92)			int _g1 = (y * this->width);
HXDLIN(  92)			int _g2 = ((y * this->width) + this->width);
HXDLIN(  92)			while((_g1 < _g2)){
HXDLIN(  92)				_g1 = (_g1 + 1);
HXDLIN(  92)				int i = (_g1 - 1);
HXDLIN(  92)				_g->push(this->inner->__get(i));
            			}
            		}
HXDLIN(  92)		return _g;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Array2D_obj,row,return )

::cpp::VirtualArray Array2D_obj::column(int x){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_99_column)
HXDLIN(  99)		::cpp::VirtualArray _g = ::cpp::VirtualArray_obj::__new(0);
HXDLIN(  99)		{
HXDLIN(  99)			int _g1 = 0;
HXDLIN(  99)			int _g2 = this->height;
HXDLIN(  99)			while((_g1 < _g2)){
HXDLIN(  99)				_g1 = (_g1 + 1);
HXDLIN(  99)				int i = (_g1 - 1);
HXDLIN(  99)				_g->push(this->inner->__get(((i * this->width) + x)));
            			}
            		}
HXDLIN(  99)		return _g;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Array2D_obj,column,return )

 ::haxe::iterators::ArrayIterator Array2D_obj::iterator(){
            	HX_GC_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_110_iterator)
HXDLIN( 110)		return  ::haxe::iterators::ArrayIterator_obj::__alloc( HX_CTX ,this->inner);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Array2D_obj,iterator,return )

 ::vision::ds::Array2D Array2D_obj::fill( ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_118_fill)
HXLINE( 119)		{
HXLINE( 119)			int _g = 0;
HXDLIN( 119)			int _g1 = this->inner->get_length();
HXDLIN( 119)			while((_g < _g1)){
HXLINE( 119)				_g = (_g + 1);
HXDLIN( 119)				int i = (_g - 1);
HXLINE( 120)				this->inner->set(i,value);
            			}
            		}
HXLINE( 121)		return ::hx::ObjectPtr<OBJ_>(this);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Array2D_obj,fill,return )

 ::vision::ds::Array2D Array2D_obj::clone(){
            	HX_GC_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_128_clone)
HXLINE( 129)		 ::vision::ds::Array2D arr =  ::vision::ds::Array2D_obj::__alloc( HX_CTX ,this->width,this->height,null());
HXLINE( 130)		arr->inner = this->inner->copy();
HXLINE( 131)		return arr;
            	}


HX_DEFINE_DYNAMIC_FUNC0(Array2D_obj,clone,return )

::String Array2D_obj::toString(){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_137_toString)
HXLINE( 138)		::String str = HX_("\n[[",2a,e6,07,00);
HXLINE( 139)		int counter = 0;
HXLINE( 140)		{
HXLINE( 140)			int _g = 0;
HXDLIN( 140)			::cpp::VirtualArray _g1 = this->inner;
HXDLIN( 140)			while((_g < _g1->get_length())){
HXLINE( 140)				 ::Dynamic item = _g1->__get(_g);
HXDLIN( 140)				_g = (_g + 1);
HXLINE( 141)				if ((counter < this->width)) {
HXLINE( 142)					::String add = (HX_(", ",74,26,00,00) + ::Std_obj::string(item));
HXLINE( 143)					if ((counter == 0)) {
HXLINE( 143)						add = add.substr(2,null());
            					}
HXLINE( 144)					str = (str + add);
HXLINE( 145)					counter = (counter + 1);
            				}
            				else {
HXLINE( 147)					counter = 0;
HXLINE( 148)					str = (str + HX_("],\n [",f6,08,61,a9));
HXLINE( 149)					::String add1 = (HX_("",00,00,00,00) + ::Std_obj::string(item));
HXLINE( 150)					str = (str + add1);
HXLINE( 151)					counter = (counter + 1);
            				}
            			}
            		}
HXLINE( 155)		return (str.substring(0,str.length) + HX_("]]",60,51,00,00));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Array2D_obj,toString,return )

int Array2D_obj::get_length(){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_159_get_length)
HXDLIN( 159)		return this->inner->get_length();
            	}


HX_DEFINE_DYNAMIC_FUNC0(Array2D_obj,get_length,return )

int Array2D_obj::set_length(int value){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_162_set_length)
HXLINE( 163)		this->inner->resize(value);
HXLINE( 164)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(Array2D_obj,set_length,return )

int Array2D_obj::set_width(int value){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_167_set_width)
HXLINE( 168)		this->inner->resize((value * this->height));
HXLINE( 169)		return (this->width = value);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Array2D_obj,set_width,return )

int Array2D_obj::set_height(int value){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_172_set_height)
HXLINE( 173)		this->inner->resize((this->width * value));
HXLINE( 174)		return (this->height = value);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Array2D_obj,set_height,return )

 ::Dynamic Array2D_obj::get_item(::Array< int > index){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_178_get_item)
HXDLIN( 178)		return this->inner->__get((index->__get(0) + (index->__get(1) * this->height)));
            	}


HX_DEFINE_DYNAMIC_FUNC1(Array2D_obj,get_item,return )

 ::Dynamic Array2D_obj::set_item(::Array< int > index, ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_182_set_item)
HXDLIN( 182)		return (this->inner->set((index->__get(0) + (index->__get(1) * this->height)),value));
            	}


HX_DEFINE_DYNAMIC_FUNC2(Array2D_obj,set_item,return )

::Array< ::Dynamic> Array2D_obj::to2DArray(){
            	HX_STACKFRAME(&_hx_pos_54eb3c9fef85e8a2_185_to2DArray)
HXLINE( 186)		::Array< ::Dynamic> arr = ::Array_obj< ::Dynamic>::__new(0);
HXLINE( 187)		{
HXLINE( 187)			int _g = 0;
HXDLIN( 187)			int _g1 = this->height;
HXDLIN( 187)			while((_g < _g1)){
HXLINE( 187)				_g = (_g + 1);
HXDLIN( 187)				int y = (_g - 1);
HXLINE( 188)				::cpp::VirtualArray _g2 = ::cpp::VirtualArray_obj::__new(0);
HXDLIN( 188)				{
HXLINE( 188)					int _g3 = (y * this->width);
HXDLIN( 188)					int _g4 = ((y * this->width) + this->width);
HXDLIN( 188)					while((_g3 < _g4)){
HXLINE( 188)						_g3 = (_g3 + 1);
HXDLIN( 188)						int i = (_g3 - 1);
HXDLIN( 188)						_g2->push(this->inner->__get(i));
            					}
            				}
HXDLIN( 188)				arr->push(_g2);
            			}
            		}
HXLINE( 191)		return arr;
            	}


HX_DEFINE_DYNAMIC_FUNC0(Array2D_obj,to2DArray,return )


::hx::ObjectPtr< Array2D_obj > Array2D_obj::__new(int width,int height, ::Dynamic fillWith) {
	::hx::ObjectPtr< Array2D_obj > __this = new Array2D_obj();
	__this->__construct(width,height,fillWith);
	return __this;
}

::hx::ObjectPtr< Array2D_obj > Array2D_obj::__alloc(::hx::Ctx *_hx_ctx,int width,int height, ::Dynamic fillWith) {
	Array2D_obj *__this = (Array2D_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Array2D_obj), true, "vision.ds.Array2D"));
	*(void **)__this = Array2D_obj::_hx_vtable;
	__this->__construct(width,height,fillWith);
	return __this;
}

Array2D_obj::Array2D_obj()
{
}

void Array2D_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Array2D);
	HX_MARK_MEMBER_NAME(inner,"inner");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_END_CLASS();
}

void Array2D_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(inner,"inner");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
}

::hx::Val Array2D_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return ::hx::Val( get_dyn() ); }
		if (HX_FIELD_EQ(inName,"set") ) { return ::hx::Val( set_dyn() ); }
		if (HX_FIELD_EQ(inName,"row") ) { return ::hx::Val( row_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"fill") ) { return ::hx::Val( fill_dyn() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"inner") ) { return ::hx::Val( inner ); }
		if (HX_FIELD_EQ(inName,"width") ) { return ::hx::Val( width ); }
		if (HX_FIELD_EQ(inName,"clone") ) { return ::hx::Val( clone_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return ::hx::Val( height ); }
		if (HX_FIELD_EQ(inName,"length") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( get_length() ); }
		if (HX_FIELD_EQ(inName,"column") ) { return ::hx::Val( column_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return ::hx::Val( iterator_dyn() ); }
		if (HX_FIELD_EQ(inName,"toString") ) { return ::hx::Val( toString_dyn() ); }
		if (HX_FIELD_EQ(inName,"get_item") ) { return ::hx::Val( get_item_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_item") ) { return ::hx::Val( set_item_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_width") ) { return ::hx::Val( set_width_dyn() ); }
		if (HX_FIELD_EQ(inName,"to2DArray") ) { return ::hx::Val( to2DArray_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return ::hx::Val( get_length_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_length") ) { return ::hx::Val( set_length_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return ::hx::Val( set_height_dyn() ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setMultiple") ) { return ::hx::Val( setMultiple_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Array2D_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"inner") ) { inner=inValue.Cast< ::cpp::VirtualArray >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_width(inValue.Cast< int >()) );width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_height(inValue.Cast< int >()) );height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { if (inCallProp == ::hx::paccAlways) return ::hx::Val( set_length(inValue.Cast< int >()) ); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Array2D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("inner",96,31,1c,be));
	outFields->push(HX_("width",06,b6,62,ca));
	outFields->push(HX_("height",e7,07,4c,02));
	outFields->push(HX_("length",e6,94,07,9f));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Array2D_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /* ::cpp::VirtualArray */ ,(int)offsetof(Array2D_obj,inner),HX_("inner",96,31,1c,be)},
	{::hx::fsInt,(int)offsetof(Array2D_obj,width),HX_("width",06,b6,62,ca)},
	{::hx::fsInt,(int)offsetof(Array2D_obj,height),HX_("height",e7,07,4c,02)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Array2D_obj_sStaticStorageInfo = 0;
#endif

static ::String Array2D_obj_sMemberFields[] = {
	HX_("inner",96,31,1c,be),
	HX_("width",06,b6,62,ca),
	HX_("height",e7,07,4c,02),
	HX_("get",96,80,4e,00),
	HX_("set",a2,9b,57,00),
	HX_("setMultiple",d2,ab,ed,ca),
	HX_("row",1a,e2,56,00),
	HX_("column",d6,4e,8b,c6),
	HX_("iterator",ee,49,9a,93),
	HX_("fill",83,ce,bb,43),
	HX_("clone",5d,13,63,48),
	HX_("toString",ac,d0,6e,38),
	HX_("get_length",af,04,8f,8f),
	HX_("set_length",23,a3,0c,93),
	HX_("set_width",69,fe,5c,f1),
	HX_("set_height",24,16,51,f6),
	HX_("get_item",9c,80,7a,c5),
	HX_("set_item",10,da,d7,73),
	HX_("to2DArray",4c,a8,75,6a),
	::String(null()) };

::hx::Class Array2D_obj::__mClass;

void Array2D_obj::__register()
{
	Array2D_obj _hx_dummy;
	Array2D_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("vision.ds.Array2D",72,04,56,aa);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Array2D_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Array2D_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Array2D_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Array2D_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace vision
} // end namespace ds