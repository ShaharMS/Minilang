﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_haxe__ds__List
#define INC_haxe__ds__List
typedef struct _haxe__ds__$List *haxe__ds__$List;
typedef struct _haxe__ds__List *haxe__ds__List;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <haxe/ds/_List/ListNode.h>


struct _haxe__ds__$List {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
};
struct _haxe__ds__List {
	hl_type *$type;
	haxe__ds___List__ListNode h;
	haxe__ds___List__ListNode q;
	int length;
};
#endif

