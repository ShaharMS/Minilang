﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC__std__Reflect
#define INC__std__Reflect
typedef struct _$Reflect *$Reflect;
typedef struct _Reflect *Reflect;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayObj.h>


struct _$Reflect {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
	vclosure* field;
	vclosure* setField;
	vclosure* getProperty;
	vclosure* fields;
};
struct _Reflect {
	hl_type *$type;
};
#endif
