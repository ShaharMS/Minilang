﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_hl__types__BytesIterator_hl_UI16
#define INC_hl__types__BytesIterator_hl_UI16
typedef struct _hl__types__$BytesIterator_hl_UI16 *hl__types__$BytesIterator_hl_UI16;
typedef struct _hl__types__BytesIterator_hl_UI16 *hl__types__BytesIterator_hl_UI16;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <haxe/iterators/ArrayIterator.h>
#include <hl/types/ArrayDyn.h>
#include <hl/types/ArrayBytes_hl_UI16.h>


struct _hl__types__$BytesIterator_hl_UI16 {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
};
struct _hl__types__BytesIterator_hl_UI16 {
	hl_type *$type;
	hl__types__ArrayDyn array;
	int current;
	hl__types__ArrayBytes_hl_UI16 a;
};
#endif

