﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_little__tools__TextTools
#define INC_little__tools__TextTools
typedef struct _little__tools__$TextTools *little__tools__$TextTools;
typedef struct _little__tools__TextTools *little__tools__TextTools;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayObj.h>


struct _little__tools__$TextTools {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
	vclosure* replaceLast;
	vclosure* replaceIfLast;
	vclosure* replaceFirst;
	vclosure* multiply;
	vclosure* sortByLength;
	vclosure* countOccurrencesOf;
	vclosure* contains;
	vclosure* remove;
	vclosure* replace;
	vclosure* containsAny;
};
struct _little__tools__TextTools {
	hl_type *$type;
};
#endif

