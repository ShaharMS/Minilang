﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_hl__NativeArrayIterator_Int
#define INC_hl__NativeArrayIterator_Int
typedef struct _hl__$NativeArrayIterator_Int *hl__$NativeArrayIterator_Int;
typedef struct _hl__NativeArrayIterator_Int *hl__NativeArrayIterator_Int;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>


struct _hl__$NativeArrayIterator_Int {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
};
struct _hl__NativeArrayIterator_Int {
	hl_type *$type;
	varray* arr;
	int pos;
	int length;
};
#endif

