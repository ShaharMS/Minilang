﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_little__interpreter__memory__ExtTree
#define INC_little__interpreter__memory__ExtTree
typedef struct _little__interpreter__memory__$ExtTree *little__interpreter__memory__$ExtTree;
typedef struct _little__interpreter__memory__ExtTree *little__interpreter__memory__ExtTree;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <little/interpreter/InterpTokens.h>
#include <haxe/ds/StringMap.h>


struct _little__interpreter__memory__$ExtTree {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
};
struct _little__interpreter__memory__ExtTree {
	hl_type *$type;
	vclosure* getter;
	int doc;
	int type;
	haxe__ds__StringMap properties;
};
#endif

