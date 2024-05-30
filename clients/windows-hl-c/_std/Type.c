﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <_std/Type.h>
#include <hl/natives.h>
extern hl_bytes_map* g$__types__;
extern hl_type t$hl_Class;
extern hl_type t$_dyn;
extern hl_type t$String;
void Type_register(vbyte*,hl__BaseType);
extern hl_type t$hl_Enum;
extern hl_type t$hl_types_ArrayObj;
void hl_types_ArrayObj_new(hl__types__ArrayObj);
extern hl_type t$_i32;
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
extern hl_type t$hl_BaseType;
extern hl__Class g$_hl_Class;
bool Std_isOfType(vdynamic*,vdynamic*);
#include <hl/Enum.h>
extern hl__$Enum g$_hl_Enum;
extern hl_type t$nul_i32;
extern String s$Unknown_enum_constructor_;
String String___add__(String,String);
extern String s$5058f1a;
vdynamic* Type_createEnumIndex(hl__BaseType,int,hl__types__ArrayDyn);
#include <hl/types/ArrayBase.h>
extern String s$Invalid_enum_index_;
String String___alloc__(vbyte*,int);
int hl_types_ArrayDyn_get_length(hl__types__ArrayDyn);
extern String s$Constructor_;
int String___compare(String,vdynamic*);
extern String s$_takes_parameters;
extern hl_type t$hl_types_ArrayBase;
extern String s$_does_not_takes_;
extern String s$_parameters;
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
hl__types__ArrayObj hl_types_ArrayObj_copy(hl__types__ArrayObj);
extern venum* g$ValueType_TUnknown;
extern venum* g$ValueType_TNull;
extern venum* g$ValueType_TInt;
extern venum* g$ValueType_TFloat;
extern venum* g$ValueType_TBool;
extern venum* g$ValueType_TFunction;
extern venum* g$ValueType_TObject;
extern hl_type t$ValueType;
int Type_enumIndex(vdynamic*);
extern hl_type t$hl_types_ArrayDyn;

bool Type_init() {
	bool r1;
	hl_bytes_map *r0, *r2;
	r0 = (hl_bytes_map*)g$__types__;
	if( !r0 ) goto label$9fea9d9_1_4;
	r1 = false;
	return r1;
	label$9fea9d9_1_4:
	r2 = hl_hballoc();
	g$__types__ = (hl_bytes_map*)r2;
	r1 = true;
	return r1;
}

hl__Class Type_initClass(hl_type* r0,hl_type* r1,vbyte* r2) {
	String r8;
	hl__Class r4, r6;
	bool r7;
	vdynamic *r3;
	int r9;
	r3 = hl_type_get_global(r1);
	r4 = (hl__Class)hl_dyn_castp(&r3,&t$_dyn,&t$hl_Class);
	if( !r4 ) goto label$9fea9d9_2_4;
	return r4;
	label$9fea9d9_2_4:
	r3 = hl_alloc_obj(r0);
	r6 = (hl__Class)hl_dyn_castp(&r3,&t$_dyn,&t$hl_Class);
	r7 = hl_type_set_global(r1,((vdynamic*)r6));
	if( r6 == NULL ) hl_null_access();
	r6->_hx___type__ = r1;
	r8 = (String)hl_alloc_obj(&t$String);
	r8->bytes = r2;
	r9 = 0;
	r9 = hl_ucs2length(r2,r9);
	r8->length = r9;
	r6->_hx___name__ = r8;
	Type_register(r2,((hl__BaseType)r6));
	return r6;
}

hl__Enum Type_initEnum(hl_type* r0,hl_type* r1) {
	String r9;
	hl__types__ArrayObj r12;
	bool r16;
	hl_bytes_map *r11;
	hl__Enum r3, r5;
	vdynamic *r2;
	int r10, r13, r14, r15;
	vbyte *r7, *r8;
	varray *r6;
	r2 = hl_type_get_global(r1);
	r3 = (hl__Enum)hl_dyn_castp(&r2,&t$_dyn,&t$hl_Enum);
	if( !r3 ) goto label$9fea9d9_3_4;
	return r3;
	label$9fea9d9_3_4:
	r2 = hl_alloc_obj(r0);
	r5 = (hl__Enum)hl_dyn_castp(&r2,&t$_dyn,&t$hl_Enum);
	r3 = r5;
	if( r5 == NULL ) hl_null_access();
	r5->_hx___type__ = r1;
	r6 = hl_type_enum_values(r1);
	r5->_hx___evalues__ = r6;
	r7 = hl_type_name(r1);
	if( r7 ) goto label$9fea9d9_3_15;
	r9 = NULL;
	goto label$9fea9d9_3_20;
	label$9fea9d9_3_15:
	r9 = (String)hl_alloc_obj(&t$String);
	r9->bytes = r7;
	r10 = 0;
	r10 = hl_ucs2length(r7,r10);
	r9->length = r10;
	label$9fea9d9_3_20:
	r5->_hx___ename__ = r9;
	r11 = hl_hballoc();
	r5->_hx___emap__ = r11;
	r12 = (hl__types__ArrayObj)hl_alloc_obj(&t$hl_types_ArrayObj);
	hl_types_ArrayObj_new(r12);
	r5->_hx___constructs__ = r12;
	r6 = hl_type_enum_fields(r1);
	r10 = 0;
	r13 = r6->size;
	label$9fea9d9_3_29:
	if( r10 >= r13 ) goto label$9fea9d9_3_47;
	r14 = r10;
	++r10;
	r8 = ((vbyte**)(r6 + 1))[r14];
	if( r3 == NULL ) hl_null_access();
	r11 = r3->_hx___emap__;
	r2 = hl_alloc_dynamic(&t$_i32);
	r2->v.i = r14;
	hl_hbset(r11,r8,r2);
	r12 = r3->_hx___constructs__;
	r9 = (String)hl_alloc_obj(&t$String);
	r9->bytes = r8;
	r15 = 0;
	r15 = hl_ucs2length(r8,r15);
	r9->length = r15;
	if( r12 == NULL ) hl_null_access();
	r15 = hl_types_ArrayObj_push(r12,((vdynamic*)r9));
	goto label$9fea9d9_3_29;
	label$9fea9d9_3_47:
	if( r3 == NULL ) hl_null_access();
	r9 = r3->_hx___ename__;
	if( r9 == NULL ) hl_null_access();
	r8 = r9->bytes;
	Type_register(r8,((hl__BaseType)r3));
	r16 = hl_type_set_global(r1,((vdynamic*)r3));
	return r3;
}

void Type_register(vbyte* r0,hl__BaseType r1) {
	hl_bytes_map *r3;
	r3 = (hl_bytes_map*)g$__types__;
	hl_hbset(r3,r0,((vdynamic*)r1));
	return;
}

hl__Class Type_getClass(vdynamic* r0) {
	hl__Class r6;
	hl_type *r1, *r4;
	vdynamic *r2;
	int r3, r5;
	r1 = r0 ? ((vdynamic*)r0)->t : &hlt_void;
	r3 = r1->kind;
	r5 = 15;
	if( r3 != r5 ) goto label$9fea9d9_5_7;
	r2 = hl_get_virtual_value(r0);
	r4 = r2 ? ((vdynamic*)r2)->t : &hlt_void;
	r1 = r4;
	label$9fea9d9_5_7:
	r3 = r1->kind;
	r5 = 11;
	if( r3 != r5 ) goto label$9fea9d9_5_13;
	r2 = hl_type_get_global(r1);
	r6 = (hl__Class)hl_dyn_castp(&r2,&t$_dyn,&t$hl_Class);
	return r6;
	label$9fea9d9_5_13:
	r6 = NULL;
	return r6;
}

hl__BaseType Type_getEnum(vdynamic* r0) {
	hl__BaseType r5;
	hl_type *r1;
	vdynamic *r2;
	int r3, r4;
	r1 = r0 ? ((vdynamic*)r0)->t : &hlt_void;
	r3 = r1->kind;
	r4 = 18;
	if( r3 != r4 ) goto label$9fea9d9_6_7;
	r2 = hl_type_get_global(r1);
	r5 = (hl__BaseType)hl_dyn_castp(&r2,&t$_dyn,&t$hl_BaseType);
	return r5;
	label$9fea9d9_6_7:
	r5 = NULL;
	return r5;
}

String Type_getClassName(hl__Class r0) {
	String r1;
	if( r0 == NULL ) hl_null_access();
	r1 = r0->_hx___name__;
	return r1;
}

String Type_getEnumName(hl__BaseType r0) {
	String r2;
	hl__Enum r1;
	r1 = (hl__Enum)hl_dyn_castp(&r0,&t$hl_BaseType,&t$hl_Enum);
	if( r1 == NULL ) hl_null_access();
	r2 = r1->_hx___ename__;
	return r2;
}

hl__Class Type_resolveClass(String r0) {
	hl__BaseType r4;
	hl__Class r6;
	bool r5;
	hl_bytes_map *r2;
	vdynamic *r1;
	vbyte *r3;
	r2 = (hl_bytes_map*)g$__types__;
	if( r0 == NULL ) hl_null_access();
	r3 = r0->bytes;
	r1 = hl_hbget(r2,r3);
	r4 = (hl__BaseType)hl_dyn_castp(&r1,&t$_dyn,&t$hl_BaseType);
	if( !r4 ) goto label$9fea9d9_9_9;
	r6 = (hl__Class)g$_hl_Class;
	r5 = Std_isOfType(((vdynamic*)r4),((vdynamic*)r6));
	if( r5 ) goto label$9fea9d9_9_11;
	label$9fea9d9_9_9:
	r6 = NULL;
	return r6;
	label$9fea9d9_9_11:
	r6 = (hl__Class)hl_dyn_castp(&r4,&t$hl_BaseType,&t$hl_Class);
	return r6;
}

hl__BaseType Type_resolveEnum(String r0) {
	hl__BaseType r4, r5;
	bool r6;
	hl_bytes_map *r2;
	hl__$Enum r7;
	vdynamic *r1;
	vbyte *r3;
	r2 = (hl_bytes_map*)g$__types__;
	if( r0 == NULL ) hl_null_access();
	r3 = r0->bytes;
	r1 = hl_hbget(r2,r3);
	r4 = (hl__BaseType)hl_dyn_castp(&r1,&t$_dyn,&t$hl_BaseType);
	if( !r4 ) goto label$9fea9d9_10_9;
	r7 = (hl__$Enum)g$_hl_Enum;
	r6 = Std_isOfType(((vdynamic*)r4),((vdynamic*)r7));
	if( r6 ) goto label$9fea9d9_10_11;
	label$9fea9d9_10_9:
	r5 = NULL;
	return r5;
	label$9fea9d9_10_11:
	return r4;
}

vdynamic* Type_createEmptyInstance(hl__Class r0) {
	hl_type *r2;
	vdynamic *r1;
	if( r0 == NULL ) hl_null_access();
	r2 = r0->_hx___type__;
	r1 = hl_alloc_obj(r2);
	return r1;
}

vdynamic* Type_createEnum(hl__BaseType r0,String r1,hl__types__ArrayDyn r2) {
	String r7, r9;
	hl_bytes_map *r5;
	hl__Enum r3;
	vdynamic *r4, *r8;
	int r10;
	vbyte *r6;
	r3 = (hl__Enum)hl_dyn_castp(&r0,&t$hl_BaseType,&t$hl_Enum);
	if( r3 == NULL ) hl_null_access();
	r5 = r3->_hx___emap__;
	if( r1 == NULL ) hl_null_access();
	r6 = r1->bytes;
	r4 = hl_hbget(r5,r6);
	r8 = (vdynamic*)hl_dyn_castp(&r4,&t$_dyn,&t$nul_i32);
	if( r8 ) goto label$9fea9d9_12_15;
	r7 = (String)s$Unknown_enum_constructor_;
	r9 = r3->_hx___ename__;
	r7 = String___add__(r7,r9);
	r9 = (String)s$5058f1a;
	r7 = String___add__(r7,r9);
	r7 = String___add__(r7,r1);
	hl_throw((vdynamic*)r7);
	label$9fea9d9_12_15:
	r10 = r8 ? r8->v.i : 0;
	r4 = Type_createEnumIndex(r0,r10,r2);
	return r4;
}

vdynamic* Type_createEnumIndex(hl__BaseType r0,int r1,hl__types__ArrayDyn r2) {
	String r7, r8, r16;
	hl__types__ArrayObj r6;
	hl_type *r19;
	bool r17;
	hl__types__ArrayBase r18;
	hl__Enum r3;
	hl__types__ArrayDyn r12;
	vdynamic *r11, *r15;
	int *r9;
	varray *r13, *r14;
	vbyte *r10;
	int r4, r5, r20, r21;
	r3 = (hl__Enum)hl_dyn_castp(&r0,&t$hl_BaseType,&t$hl_Enum);
	r5 = 0;
	if( r1 < r5 ) goto label$9fea9d9_13_8;
	if( r3 == NULL ) hl_null_access();
	r6 = r3->_hx___constructs__;
	if( r6 == NULL ) hl_null_access();
	r5 = r6->length;
	if( r1 < r5 ) goto label$9fea9d9_13_20;
	label$9fea9d9_13_8:
	r7 = (String)s$Invalid_enum_index_;
	if( r3 == NULL ) hl_null_access();
	r8 = r3->_hx___ename__;
	r7 = String___add__(r7,r8);
	r8 = (String)s$5058f1a;
	r7 = String___add__(r7,r8);
	r4 = r1;
	r9 = &r4;
	r10 = hl_itos(r4,r9);
	r8 = String___alloc__(r10,r4);
	r7 = String___add__(r7,r8);
	hl_throw((vdynamic*)r7);
	label$9fea9d9_13_20:
	if( !r2 ) goto label$9fea9d9_13_25;
	if( r2 == NULL ) hl_null_access();
	r4 = hl_types_ArrayDyn_get_length(r2);
	r5 = 0;
	if( r4 != r5 ) goto label$9fea9d9_13_55;
	label$9fea9d9_13_25:
	r13 = r3->_hx___evalues__;
	r5 = r13->size;
	if( r1 < r5 ) goto label$9fea9d9_13_30;
	r15 = NULL;
	goto label$9fea9d9_13_32;
	label$9fea9d9_13_30:
	r14 = r3->_hx___evalues__;
	r15 = ((vdynamic**)(r14 + 1))[r1];
	label$9fea9d9_13_32:
	if( r15 ) goto label$9fea9d9_13_54;
	r7 = (String)s$Constructor_;
	r8 = r3->_hx___ename__;
	r7 = String___add__(r7,r8);
	r8 = (String)s$5058f1a;
	r7 = String___add__(r7,r8);
	r6 = r3->_hx___constructs__;
	if( r6 == NULL ) hl_null_access();
	r5 = r6->length;
	if( ((unsigned)r1) < ((unsigned)r5) ) goto label$9fea9d9_13_44;
	r8 = NULL;
	goto label$9fea9d9_13_50;
	label$9fea9d9_13_44:
	r14 = r6->array;
	r15 = ((vdynamic**)(r14 + 1))[r1];
	r8 = (String)r15;
	r16 = (String)hl_dyn_castp(&r15,&t$_dyn,&t$String);
	if( r8 == r16 || (r8 && r16 && String___compare(r8,(vdynamic*)r16) == 0) ) goto label$9fea9d9_13_50;
	hl_assert();
	label$9fea9d9_13_50:
	r7 = String___add__(r7,r8);
	r8 = (String)s$_takes_parameters;
	r7 = String___add__(r7,r8);
	hl_throw((vdynamic*)r7);
	label$9fea9d9_13_54:
	return r15;
	label$9fea9d9_13_55:
	r12 = r2;
	r18 = r2->array;
	if( r18 == NULL ) hl_null_access();
	r17 = ((bool (*)(hl__types__ArrayBase))r18->$type->vobj_proto[17])(r18);
	if( r17 ) goto label$9fea9d9_13_81;
	r18 = r2->array;
	if( r18 == NULL ) hl_null_access();
	r4 = r18->length;
	r19 = &t$_dyn;
	r14 = hl_alloc_array(r19,r4);
	r13 = r14;
	r5 = 0;
	r18 = r2->array;
	if( r18 == NULL ) hl_null_access();
	r20 = r18->length;
	label$9fea9d9_13_70:
	if( r5 >= r20 ) goto label$9fea9d9_13_80;
	r21 = r5;
	++r5;
	if( r12 == NULL ) hl_null_access();
	r18 = r12->array;
	if( r18 == NULL ) hl_null_access();
	r11 = ((vdynamic* (*)(hl__types__ArrayBase,int))r18->$type->vobj_proto[0])(r18,r21);
	((vdynamic**)(r13 + 1))[r21] = r11;
	goto label$9fea9d9_13_70;
	label$9fea9d9_13_80:
	goto label$9fea9d9_13_86;
	label$9fea9d9_13_81:
	r18 = r2->array;
	r6 = (hl__types__ArrayObj)hl_dyn_castp(&r18,&t$hl_types_ArrayBase,&t$hl_types_ArrayObj);
	if( r6 == NULL ) hl_null_access();
	r14 = r6->array;
	r13 = r14;
	label$9fea9d9_13_86:
	if( r3 == NULL ) hl_null_access();
	r19 = r3->_hx___type__;
	if( r12 == NULL ) hl_null_access();
	r18 = r12->array;
	if( r18 == NULL ) hl_null_access();
	r5 = r18->length;
	r11 = hl_alloc_enum_dyn(r19,r1,r13,r5);
	if( r11 ) goto label$9fea9d9_13_122;
	r7 = (String)s$Constructor_;
	r8 = r3->_hx___ename__;
	r7 = String___add__(r7,r8);
	r8 = (String)s$5058f1a;
	r7 = String___add__(r7,r8);
	r6 = r3->_hx___constructs__;
	if( r6 == NULL ) hl_null_access();
	r5 = r6->length;
	if( ((unsigned)r1) < ((unsigned)r5) ) goto label$9fea9d9_13_105;
	r8 = NULL;
	goto label$9fea9d9_13_111;
	label$9fea9d9_13_105:
	r14 = r6->array;
	r15 = ((vdynamic**)(r14 + 1))[r1];
	r8 = (String)r15;
	r16 = (String)hl_dyn_castp(&r15,&t$_dyn,&t$String);
	if( r8 == r16 || (r8 && r16 && String___compare(r8,(vdynamic*)r16) == 0) ) goto label$9fea9d9_13_111;
	hl_assert();
	label$9fea9d9_13_111:
	r7 = String___add__(r7,r8);
	r8 = (String)s$_does_not_takes_;
	r7 = String___add__(r7,r8);
	r4 = r13->size;
	r9 = &r4;
	r10 = hl_itos(r4,r9);
	r8 = String___alloc__(r10,r4);
	r7 = String___add__(r7,r8);
	r8 = (String)s$_parameters;
	r7 = String___add__(r7,r8);
	hl_throw((vdynamic*)r7);
	label$9fea9d9_13_122:
	return r11;
}

hl__types__ArrayObj Type_getInstanceFields(hl__Class r0) {
	String r9;
	hl__types__ArrayObj r3;
	hl_type *r2;
	vbyte *r8;
	int r5, r6, r7;
	varray *r1, *r4;
	if( r0 == NULL ) hl_null_access();
	r2 = r0->_hx___type__;
	r1 = hl_type_instance_fields(r2);
	r2 = &t$String;
	r5 = 0;
	r4 = hl_alloc_array(r2,r5);
	r3 = hl_types_ArrayObj_alloc(r4);
	r5 = 0;
	label$9fea9d9_14_8:
	r7 = r1->size;
	if( r5 >= r7 ) goto label$9fea9d9_14_21;
	r8 = ((vbyte**)(r1 + 1))[r5];
	++r5;
	r9 = (String)hl_alloc_obj(&t$String);
	r9->bytes = r8;
	r6 = 0;
	r6 = hl_ucs2length(r8,r6);
	r9->length = r6;
	if( r3 == NULL ) hl_null_access();
	r6 = hl_types_ArrayObj_push(r3,((vdynamic*)r9));
	goto label$9fea9d9_14_8;
	label$9fea9d9_14_21:
	return r3;
}

hl__types__ArrayObj Type_getEnumConstructs(hl__BaseType r0) {
	hl__types__ArrayObj r2;
	hl__Enum r1;
	r1 = (hl__Enum)hl_dyn_castp(&r0,&t$hl_BaseType,&t$hl_Enum);
	if( r1 == NULL ) hl_null_access();
	r2 = r1->_hx___constructs__;
	if( r2 == NULL ) hl_null_access();
	r2 = hl_types_ArrayObj_copy(r2);
	return r2;
}

venum* Type_typeof(vdynamic* r0) {
	hl__BaseType r8;
	hl__Class r7;
	venum *r4;
	hl_type *r1;
	double r5, r6;
	vdynamic *r2;
	int r3;
	r1 = r0 ? ((vdynamic*)r0)->t : &hlt_void;
	r3 = r1->kind;
	switch(r3) {
		default:
		case 4:
		case 8:
		case 9:
		case 12:
		case 13:
		case 14:
		case 17:
			r4 = (venum*)g$ValueType_TUnknown;
			return r4;
		case 0:
			r4 = (venum*)g$ValueType_TNull;
			return r4;
		case 1:
		case 2:
		case 3:
			r4 = (venum*)g$ValueType_TInt;
			return r4;
		case 5:
		case 6:
			r3 = (int)hl_dyn_casti(&r0,&t$_dyn,&t$_i32);
			r5 = (double)r3;
			r6 = (double)hl_dyn_castd(&r0,&t$_dyn);
			if( r5 != r6 ) goto label$9fea9d9_16_15;
			r4 = (venum*)g$ValueType_TInt;
			return r4;
			label$9fea9d9_16_15:
			r4 = (venum*)g$ValueType_TFloat;
			return r4;
		case 7:
			r4 = (venum*)g$ValueType_TBool;
			return r4;
		case 10:
			r4 = (venum*)g$ValueType_TFunction;
			return r4;
		case 11:
			r7 = Type_getClass(r0);
			r8 = (hl__BaseType)g$_hl_Class;
			if( r7 == ((hl__Class)r8) ) goto label$9fea9d9_16_25;
			if( r7 ) goto label$9fea9d9_16_27;
			label$9fea9d9_16_25:
			r4 = (venum*)g$ValueType_TObject;
			return r4;
			label$9fea9d9_16_27:
			r7 = (hl__Class)hl_dyn_castp(&r7,&t$hl_Class,&t$hl_Class);
			r4 = hl_alloc_enum(&t$ValueType,6);
			((ValueType_TClass*)r4)->p0 = r7;
			return r4;
		case 15:
			r2 = hl_get_virtual_value(r0);
			if( r2 ) goto label$9fea9d9_16_34;
			r4 = (venum*)g$ValueType_TObject;
			return r4;
			label$9fea9d9_16_34:
			r4 = Type_typeof(r2);
			return r4;
		case 16:
			r4 = (venum*)g$ValueType_TObject;
			return r4;
		case 18:
			r8 = Type_getEnum(r0);
			r4 = hl_alloc_enum(&t$ValueType,7);
			((ValueType_TEnum*)r4)->p0 = r8;
			return r4;
	}
}

String Type_enumConstructor(vdynamic* r0) {
	String r7, r9;
	hl__BaseType r1;
	hl__types__ArrayObj r4;
	hl__Enum r3;
	vdynamic *r2;
	varray *r8;
	int r5, r6;
	r1 = Type_getEnum(r0);
	r3 = (hl__Enum)hl_dyn_castp(&r1,&t$hl_BaseType,&t$hl_Enum);
	if( r3 == NULL ) hl_null_access();
	r4 = r3->_hx___constructs__;
	if( r4 == NULL ) hl_null_access();
	r5 = Type_enumIndex(r0);
	r6 = r4->length;
	if( ((unsigned)r5) < ((unsigned)r6) ) goto label$9fea9d9_17_10;
	r7 = NULL;
	goto label$9fea9d9_17_16;
	label$9fea9d9_17_10:
	r8 = r4->array;
	r2 = ((vdynamic**)(r8 + 1))[r5];
	r7 = (String)r2;
	r9 = (String)hl_dyn_castp(&r2,&t$_dyn,&t$String);
	if( r7 == r9 || (r7 && r9 && String___compare(r7,(vdynamic*)r9) == 0) ) goto label$9fea9d9_17_16;
	hl_assert();
	label$9fea9d9_17_16:
	return r7;
}

hl__types__ArrayDyn Type_enumParameters(vdynamic* r0) {
	hl__types__ArrayObj r3;
	hl__types__ArrayDyn r4;
	vdynamic *r1;
	varray *r2;
	if( r0 ) goto label$9fea9d9_18_3;
	if( r0 == NULL ) hl_null_access();
	{
		r1 = (vdynamic*)hl_dyn_call((vclosure*)r0,NULL,0);
	}
	label$9fea9d9_18_3:
	r2 = hl_enum_parameters(r0);
	r3 = hl_types_ArrayObj_alloc(r2);
	r4 = (hl__types__ArrayDyn)hl_dyn_castp(&r3,&t$hl_types_ArrayObj,&t$hl_types_ArrayDyn);
	return r4;
}

int Type_enumIndex(vdynamic* r0) {
	int r1;
	if( r0 == NULL ) hl_null_access();
	r1 = HL__ENUM_INDEX__(r0);
	return r1;
}

