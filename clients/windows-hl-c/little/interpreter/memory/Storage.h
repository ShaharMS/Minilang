﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_little__interpreter__memory__Storage
#define INC_little__interpreter__memory__Storage
typedef struct _little__interpreter__memory__$Storage *little__interpreter__memory__$Storage;
typedef struct _little__interpreter__memory__Storage *little__interpreter__memory__Storage;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <little/interpreter/memory/Memory.h>
#include <haxe/io/Bytes.h>


struct _little__interpreter__memory__$Storage {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
};
struct _little__interpreter__memory__Storage {
	hl_type *$type;
	little__interpreter__memory__Memory parent;
	haxe__io__Bytes reserved;
	haxe__io__Bytes storage;
};
#endif

