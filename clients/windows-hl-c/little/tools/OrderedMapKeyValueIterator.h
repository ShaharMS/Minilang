﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_little__tools__OrderedMapKeyValueIterator
#define INC_little__tools__OrderedMapKeyValueIterator
typedef struct _little__tools__$OrderedMapKeyValueIterator *little__tools__$OrderedMapKeyValueIterator;
typedef struct _little__tools__OrderedMapKeyValueIterator *little__tools__OrderedMapKeyValueIterator;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayDyn.h>


struct _little__tools__$OrderedMapKeyValueIterator {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
};
struct _little__tools__OrderedMapKeyValueIterator {
	hl_type *$type;
	int current;
	hl__types__ArrayDyn karray;
	hl__types__ArrayDyn varray;
};
#endif
