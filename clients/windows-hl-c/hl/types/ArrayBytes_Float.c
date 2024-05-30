﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <hl/types/ArrayBytes_Float.h>
extern hl_type t$_f64;
extern hl_type t$hl_types_ArrayBytes_Float;
void hl_types_ArrayBytes_Float_new(hl__types__ArrayBytes_Float);
#include <hl/natives.h>
#include <_std/String.h>
#include <_std/StringBuf.h>
extern hl_type t$StringBuf;
void StringBuf_new(StringBuf);
void StringBuf_add(StringBuf,vdynamic*);
String StringBuf_toString(StringBuf);
void hl_types_ArrayBytes_Float___expand(hl__types__ArrayBytes_Float,int);
#include <haxe/io/Error.h>
extern hl_type t$hl_types_ArrayAccess;
extern venum* g$haxe_io_Error_OutsideBounds;
vbyte* hl__Bytes_Bytes_Impl__sub(vbyte*,int,int);
extern hl_type t$_i32;
extern hl_type t$fun_026a163;
void StringBuf_addChar(StringBuf,int);
int hl_types_ArrayBytes_Float_indexOf(hl__types__ArrayBytes_Float,double,vdynamic*);
#include <hl/types/BytesIterator_Float.h>
#include <haxe/iterators/ArrayIterator.h>
extern hl_type t$hl_types_BytesIterator_Float;
void hl_types_BytesIterator_Float_new(hl__types__BytesIterator_Float,hl__types__ArrayBytes_Float);
#include <haxe/iterators/ArrayKeyValueIterator.h>
#include <hl/types/ArrayDyn.h>
extern hl_type t$haxe_iterators_ArrayKeyValueIterator;
extern hl_type t$hl_types_ArrayDyn;
void haxe_iterators_ArrayKeyValueIterator_new(haxe__iterators__ArrayKeyValueIterator,hl__types__ArrayDyn);
#include <hl/types/ArrayObj.h>
extern hl_type t$hl_types_ArrayObj;
void hl_types_ArrayObj_new(hl__types__ArrayObj);
void hl_types_ArrayObj___expand(hl__types__ArrayObj,int);
hl__types__ArrayDyn hl_types_ArrayDyn_alloc(hl__types__ArrayBase,bool*);
extern hl_type t$_dyn;
extern hl_type t$fun_cae6940;
extern String s$Invalid_array_index_;
String String___alloc__(vbyte*,int);
String String___add__(String,String);

int hl_types_ArrayBytes_Float_sort__$1(vclosure* r0,int r1,int r2) {
	double r3, r4;
	r3 = (double)r1;
	r4 = (double)r2;
	r1 = r0->hasValue ? ((int (*)(vdynamic*,double,double))r0->fun)((vdynamic*)r0->value,r3,r4) : ((int (*)(double,double))r0->fun)(r3,r4);
	return r1;
}

int hl_types_ArrayBytes_Float_sortDyn__$1(vclosure* r0,double r1,double r2) {
	vdynamic *r3, *r4;
	int r5;
	r3 = hl_alloc_dynamic(&t$_f64);
	r3->v.d = r1;
	r4 = hl_alloc_dynamic(&t$_f64);
	r4->v.d = r2;
	r5 = r0->hasValue ? ((int (*)(vdynamic*,vdynamic*,vdynamic*))r0->fun)((vdynamic*)r0->value,r3,r4) : ((int (*)(vdynamic*,vdynamic*))r0->fun)(r3,r4);
	return r5;
}

hl__types__ArrayBytes_Float hl_types_ArrayBytes_Float_concat(hl__types__ArrayBytes_Float r0,hl__types__ArrayBytes_Float r1) {
	hl__types__ArrayBytes_Float r2;
	vbyte *r6, *r7, *r8, *r9, *r12;
	int r4, r5, r10, r11, r13;
	r2 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r2);
	r4 = r0->length;
	if( r1 == NULL ) hl_null_access();
	r5 = r1->length;
	r4 = r4 + r5;
	r2->size = r4;
	r2->length = r4;
	r6 = r0->bytes;
	r4 = r2->length;
	r5 = 3;
	r4 = r4 << r5;
	r7 = hl_alloc_bytes(r4);
	r2->bytes = r7;
	r7 = r0->bytes;
	r4 = r0->length;
	r5 = 3;
	r4 = r4 << r5;
	r8 = r2->bytes;
	r5 = 0;
	r9 = r0->bytes;
	r10 = 0;
	hl_bytes_blit(r8,r5,r9,r10,r4);
	r8 = r0->bytes;
	r9 = r2->bytes;
	r12 = r1->bytes;
	r10 = 0;
	r11 = r1->length;
	r13 = 3;
	r11 = r11 << r13;
	hl_bytes_blit(r9,r4,r12,r10,r11);
	return r2;
}

String hl_types_ArrayBytes_Float_join(hl__types__ArrayBytes_Float r0,String r1) {
	String r8;
	StringBuf r2;
	double r10;
	vdynamic *r11;
	vbyte *r9;
	int r4, r5, r6, r7;
	r2 = (StringBuf)hl_alloc_obj(&t$StringBuf);
	StringBuf_new(r2);
	r4 = 0;
	r5 = r0->length;
	label$d05ef5b_4_4:
	if( r4 >= r5 ) goto label$d05ef5b_4_20;
	r6 = r4;
	++r4;
	r7 = 0;
	if( r7 >= r6 ) goto label$d05ef5b_4_12;
	if( r2 == NULL ) hl_null_access();
	StringBuf_add(r2,((vdynamic*)r1));
	label$d05ef5b_4_12:
	r9 = r0->bytes;
	if( r2 == NULL ) hl_null_access();
	r7 = 3;
	r7 = r6 << r7;
	r10 = *(double*)(r9 + r7);
	r11 = hl_alloc_dynamic(&t$_f64);
	r11->v.d = r10;
	StringBuf_add(r2,((vdynamic*)r11));
	goto label$d05ef5b_4_4;
	label$d05ef5b_4_20:
	if( r2 == NULL ) hl_null_access();
	r8 = StringBuf_toString(r2);
	return r8;
}

vdynamic* hl_types_ArrayBytes_Float_pop(hl__types__ArrayBytes_Float r0) {
	double r6, r8;
	vdynamic *r3;
	vbyte *r4, *r5;
	int r1, r2, r7, r9;
	r1 = r0->length;
	r2 = 0;
	if( r1 != r2 ) goto label$d05ef5b_5_5;
	r3 = NULL;
	return r3;
	label$d05ef5b_5_5:
	r1 = r0->length;
	--r1;
	r0->length = r1;
	r4 = r0->bytes;
	r1 = r0->length;
	r7 = 3;
	r7 = r1 << r7;
	r6 = *(double*)(r4 + r7);
	r5 = r0->bytes;
	r2 = r0->length;
	r7 = 0;
	r8 = (double)r7;
	r9 = 3;
	r9 = r2 << r9;
	*(double*)(r5 + r9) = r8;
	r3 = hl_alloc_dynamic(&t$_f64);
	r3->v.d = r6;
	return r3;
}

int hl_types_ArrayBytes_Float_push(hl__types__ArrayBytes_Float r0,double r1) {
	vbyte *r6;
	int r2, r4, r5;
	r2 = r0->length;
	r4 = r0->size;
	if( r4 != r2 ) goto label$d05ef5b_6_5;
	hl_types_ArrayBytes_Float___expand(r0,r2);
	goto label$d05ef5b_6_8;
	label$d05ef5b_6_5:
	r4 = r0->length;
	++r4;
	r0->length = r4;
	label$d05ef5b_6_8:
	r6 = r0->bytes;
	r5 = 3;
	r5 = r2 << r5;
	*(double*)(r6 + r5) = r1;
	r4 = r0->length;
	return r4;
}

void hl_types_ArrayBytes_Float_reverse(hl__types__ArrayBytes_Float r0) {
	double r9, r12;
	vbyte *r7, *r8, *r11;
	int r1, r3, r4, r5, r6, r10;
	r1 = 0;
	r3 = r0->length;
	r4 = 1;
	r3 = r3 >> r4;
	label$d05ef5b_7_4:
	if( r1 >= r3 ) goto label$d05ef5b_7_29;
	r4 = r1;
	++r1;
	r5 = r0->length;
	r6 = 1;
	r5 = r5 - r6;
	r5 = r5 - r4;
	r7 = r0->bytes;
	r10 = 3;
	r10 = r4 << r10;
	r9 = *(double*)(r7 + r10);
	r8 = r0->bytes;
	r11 = r0->bytes;
	r10 = 3;
	r10 = r5 << r10;
	r12 = *(double*)(r11 + r10);
	r10 = 3;
	r10 = r4 << r10;
	*(double*)(r8 + r10) = r12;
	r8 = r0->bytes;
	r10 = 3;
	r10 = r5 << r10;
	*(double*)(r8 + r10) = r9;
	goto label$d05ef5b_7_4;
	label$d05ef5b_7_29:
	return;
}

vdynamic* hl_types_ArrayBytes_Float_shift(hl__types__ArrayBytes_Float r0) {
	double r7, r15;
	vdynamic *r4;
	vbyte *r5, *r6, *r8, *r9, *r10, *r11;
	int r2, r3, r12, r13, r14;
	r2 = r0->length;
	r3 = 0;
	if( r2 != r3 ) goto label$d05ef5b_8_5;
	r4 = NULL;
	return r4;
	label$d05ef5b_8_5:
	r5 = r0->bytes;
	r2 = 0;
	r3 = 3;
	r3 = r2 << r3;
	r7 = *(double*)(r5 + r3);
	r2 = r0->length;
	--r2;
	r0->length = r2;
	r6 = r0->bytes;
	r8 = r0->bytes;
	r9 = r0->bytes;
	r2 = 1;
	r3 = 3;
	r2 = r2 << r3;
	r10 = r0->bytes;
	r3 = 0;
	r13 = r0->length;
	r14 = 3;
	r13 = r13 << r14;
	hl_bytes_blit(r6,r3,r8,r2,r13);
	r11 = r0->bytes;
	r3 = r0->length;
	r12 = 0;
	r15 = (double)r12;
	r13 = 3;
	r13 = r3 << r13;
	*(double*)(r11 + r13) = r15;
	r4 = hl_alloc_dynamic(&t$_f64);
	r4->v.d = r7;
	return r4;
}

void hl_types_ArrayBytes_Float_blit(hl__types__ArrayBytes_Float r0,int r1,hl__types__ArrayAccess r2,int r3,int r4) {
	venum *r9;
	hl__types__ArrayBytes_Float r5;
	vbyte *r10, *r11, *r12, *r13, *r15;
	int r7, r8, r14, r16, r17;
	r5 = (hl__types__ArrayBytes_Float)hl_dyn_castp(&r2,&t$hl_types_ArrayAccess,&t$hl_types_ArrayBytes_Float);
	r8 = 0;
	if( r1 < r8 ) goto label$d05ef5b_9_14;
	r8 = 0;
	if( r3 < r8 ) goto label$d05ef5b_9_14;
	r8 = 0;
	if( r4 < r8 ) goto label$d05ef5b_9_14;
	r7 = r1 + r4;
	r8 = r0->length;
	if( r8 < r7 ) goto label$d05ef5b_9_14;
	r7 = r3 + r4;
	if( r5 == NULL ) hl_null_access();
	r8 = r5->length;
	if( r8 >= r7 ) goto label$d05ef5b_9_16;
	label$d05ef5b_9_14:
	r9 = (venum*)g$haxe_io_Error_OutsideBounds;
	hl_throw((vdynamic*)r9);
	label$d05ef5b_9_16:
	r10 = r0->bytes;
	r11 = r0->bytes;
	r8 = 3;
	r7 = r1 << r8;
	r12 = r5->bytes;
	r13 = r0->bytes;
	r14 = 3;
	r8 = r3 << r14;
	r15 = r0->bytes;
	r17 = 3;
	r16 = r4 << r17;
	hl_bytes_blit(r10,r7,r12,r8,r16);
	return;
}

hl__types__ArrayBase hl_types_ArrayBytes_Float_slice(hl__types__ArrayBytes_Float r0,int r1,vdynamic* r2) {
	hl__types__ArrayBytes_Float r8;
	vbyte *r9, *r10, *r11, *r12;
	int r4, r5, r6, r7, r13, r14;
	r5 = 0;
	if( r1 >= r5 ) goto label$d05ef5b_10_9;
	r4 = r0->length;
	r4 = r4 + r1;
	r1 = r4;
	r5 = 0;
	if( r4 >= r5 ) goto label$d05ef5b_10_9;
	r4 = 0;
	r1 = r4;
	label$d05ef5b_10_9:
	if( r2 ) goto label$d05ef5b_10_12;
	r5 = r0->length;
	goto label$d05ef5b_10_20;
	label$d05ef5b_10_12:
	r5 = r2 ? r2->v.i : 0;
	r6 = 0;
	if( r5 >= r6 ) goto label$d05ef5b_10_17;
	r6 = r0->length;
	r5 = r5 + r6;
	label$d05ef5b_10_17:
	r6 = r0->length;
	if( r6 >= r5 ) goto label$d05ef5b_10_20;
	r5 = r0->length;
	label$d05ef5b_10_20:
	r5 = r5 - r1;
	r7 = 0;
	if( r5 >= r7 ) goto label$d05ef5b_10_26;
	r8 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r8);
	return ((hl__types__ArrayBase)r8);
	label$d05ef5b_10_26:
	r8 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r8);
	r8->size = r5;
	r8->length = r5;
	r9 = r0->bytes;
	r10 = r0->bytes;
	r7 = 3;
	r6 = r1 << r7;
	r11 = r0->bytes;
	r14 = 3;
	r13 = r5 << r14;
	r12 = hl__Bytes_Bytes_Impl__sub(r9,r6,r13);
	r8->bytes = r12;
	return ((hl__types__ArrayBase)r8);
}

void hl_types_ArrayBytes_Float_sort(hl__types__ArrayBytes_Float r0,vclosure* r1) {
	hl_type *r3, *r4;
	vclosure *r8;
	int r6, r7;
	vbyte *r5;
	r3 = &t$_f64;
	r4 = &t$_i32;
	if( hl_same_type(r3,r4) != 0 ) {} else goto label$d05ef5b_11_12;
	r5 = r0->bytes;
	r6 = 0;
	r7 = r0->length;
	if( r1 ) goto label$d05ef5b_11_9;
	r8 = NULL;
	goto label$d05ef5b_11_10;
	label$d05ef5b_11_9:
	r8 = hl_alloc_closure_ptr(&t$fun_026a163,hl_types_ArrayBytes_Float_sort__$1,r1);
	label$d05ef5b_11_10:
	hl_bsort_i32(r5,r6,r7,r8);
	goto label$d05ef5b_11_16;
	label$d05ef5b_11_12:
	r5 = r0->bytes;
	r6 = 0;
	r7 = r0->length;
	hl_bsort_f64(r5,r6,r7,r1);
	label$d05ef5b_11_16:
	return;
}

hl__types__ArrayBase hl_types_ArrayBytes_Float_splice(hl__types__ArrayBytes_Float r0,int r1,int r2) {
	hl__types__ArrayBytes_Float r6;
	vbyte *r7, *r8, *r9, *r10, *r13, *r14, *r15, *r17, *r18, *r19, *r23;
	int r4, r5, r11, r12, r16, r20, r21, r22;
	r5 = 0;
	if( r2 >= r5 ) goto label$d05ef5b_12_5;
	r6 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r6);
	return ((hl__types__ArrayBase)r6);
	label$d05ef5b_12_5:
	r5 = 0;
	if( r1 >= r5 ) goto label$d05ef5b_12_14;
	r4 = r0->length;
	r4 = r4 + r1;
	r1 = r4;
	r5 = 0;
	if( r4 >= r5 ) goto label$d05ef5b_12_14;
	r4 = 0;
	r1 = r4;
	label$d05ef5b_12_14:
	r5 = r0->length;
	if( r5 >= r1 ) goto label$d05ef5b_12_21;
	r4 = 0;
	r1 = r4;
	r4 = 0;
	r2 = r4;
	goto label$d05ef5b_12_31;
	label$d05ef5b_12_21:
	r4 = r1 + r2;
	r5 = r0->length;
	if( r5 >= r4 ) goto label$d05ef5b_12_31;
	r4 = r0->length;
	r4 = r4 - r1;
	r2 = r4;
	r5 = 0;
	if( r4 >= r5 ) goto label$d05ef5b_12_31;
	r4 = 0;
	r2 = r4;
	label$d05ef5b_12_31:
	r5 = 0;
	if( r2 != r5 ) goto label$d05ef5b_12_36;
	r6 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r6);
	return ((hl__types__ArrayBase)r6);
	label$d05ef5b_12_36:
	r6 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r6);
	r7 = r0->bytes;
	r8 = r0->bytes;
	r5 = 3;
	r4 = r1 << r5;
	r9 = r0->bytes;
	r12 = 3;
	r11 = r2 << r12;
	r10 = hl__Bytes_Bytes_Impl__sub(r7,r4,r11);
	r6->bytes = r10;
	r6->length = r2;
	r6->size = r2;
	r5 = r1 + r2;
	r10 = r0->bytes;
	r13 = r0->bytes;
	r12 = 3;
	r11 = r1 << r12;
	r14 = r0->bytes;
	r15 = r0->bytes;
	r16 = 3;
	r12 = r5 << r16;
	r17 = r0->bytes;
	r21 = r0->length;
	r21 = r21 - r5;
	r22 = 3;
	r21 = r21 << r22;
	hl_bytes_blit(r10,r11,r14,r12,r21);
	r18 = r0->bytes;
	r19 = r0->bytes;
	r16 = r0->length;
	r16 = r16 - r2;
	r20 = 3;
	r16 = r16 << r20;
	r23 = r0->bytes;
	r22 = 3;
	r21 = r2 << r22;
	r22 = 0;
	hl_bytes_fill(r18,r16,r21,r22);
	r20 = r0->length;
	r20 = r20 - r2;
	r0->length = r20;
	return ((hl__types__ArrayBase)r6);
}

String hl_types_ArrayBytes_Float_toString(hl__types__ArrayBytes_Float r0) {
	String r11;
	StringBuf r1;
	double r9;
	vdynamic *r10;
	vbyte *r8;
	int r3, r4, r5, r6, r7;
	r1 = (StringBuf)hl_alloc_obj(&t$StringBuf);
	StringBuf_new(r1);
	r3 = 91;
	StringBuf_addChar(r1,r3);
	r3 = 0;
	r4 = r0->length;
	label$d05ef5b_13_6:
	if( r3 >= r4 ) goto label$d05ef5b_13_23;
	r5 = r3;
	++r3;
	r7 = 0;
	if( r7 >= r5 ) goto label$d05ef5b_13_15;
	if( r1 == NULL ) hl_null_access();
	r6 = 44;
	StringBuf_addChar(r1,r6);
	label$d05ef5b_13_15:
	r8 = r0->bytes;
	if( r1 == NULL ) hl_null_access();
	r7 = 3;
	r7 = r5 << r7;
	r9 = *(double*)(r8 + r7);
	r10 = hl_alloc_dynamic(&t$_f64);
	r10->v.d = r9;
	StringBuf_add(r1,((vdynamic*)r10));
	goto label$d05ef5b_13_6;
	label$d05ef5b_13_23:
	if( r1 == NULL ) hl_null_access();
	r3 = 93;
	StringBuf_addChar(r1,r3);
	r11 = StringBuf_toString(r1);
	return r11;
}

void hl_types_ArrayBytes_Float_unshift(hl__types__ArrayBytes_Float r0,double r1) {
	vbyte *r5, *r6, *r7, *r8, *r9;
	int r3, r4, r10, r11, r12;
	r3 = r0->length;
	r4 = r0->size;
	if( r3 != r4 ) goto label$d05ef5b_14_6;
	r3 = r0->length;
	hl_types_ArrayBytes_Float___expand(r0,r3);
	goto label$d05ef5b_14_9;
	label$d05ef5b_14_6:
	r3 = r0->length;
	++r3;
	r0->length = r3;
	label$d05ef5b_14_9:
	r5 = r0->bytes;
	r6 = r0->bytes;
	r3 = 1;
	r4 = 3;
	r3 = r3 << r4;
	r7 = r0->bytes;
	r9 = r0->bytes;
	r10 = 0;
	r11 = r0->length;
	r12 = 1;
	r11 = r11 - r12;
	r12 = 3;
	r11 = r11 << r12;
	hl_bytes_blit(r5,r3,r9,r10,r11);
	r8 = r0->bytes;
	r4 = 0;
	r10 = 3;
	r10 = r4 << r10;
	*(double*)(r8 + r10) = r1;
	return;
}

void hl_types_ArrayBytes_Float_insert(hl__types__ArrayBytes_Float r0,int r1,double r2) {
	vbyte *r6, *r7, *r8, *r9, *r11, *r12;
	int r4, r5, r10, r13, r14, r15;
	r5 = 0;
	if( r1 >= r5 ) goto label$d05ef5b_15_10;
	r4 = r0->length;
	r4 = r4 + r1;
	r1 = r4;
	r5 = 0;
	if( r4 >= r5 ) goto label$d05ef5b_15_9;
	r4 = 0;
	r1 = r4;
	label$d05ef5b_15_9:
	goto label$d05ef5b_15_14;
	label$d05ef5b_15_10:
	r5 = r0->length;
	if( r5 >= r1 ) goto label$d05ef5b_15_14;
	r4 = r0->length;
	r1 = r4;
	label$d05ef5b_15_14:
	r4 = r0->length;
	r5 = r0->size;
	if( r4 != r5 ) goto label$d05ef5b_15_20;
	r4 = r0->length;
	hl_types_ArrayBytes_Float___expand(r0,r4);
	goto label$d05ef5b_15_23;
	label$d05ef5b_15_20:
	r4 = r0->length;
	++r4;
	r0->length = r4;
	label$d05ef5b_15_23:
	r6 = r0->bytes;
	r7 = r0->bytes;
	r5 = 1;
	r4 = r1 + r5;
	r5 = 3;
	r4 = r4 << r5;
	r8 = r0->bytes;
	r9 = r0->bytes;
	r10 = 3;
	r5 = r1 << r10;
	r11 = r0->bytes;
	r14 = r0->length;
	r14 = r14 - r1;
	r15 = 1;
	r14 = r14 - r15;
	r15 = 3;
	r14 = r14 << r15;
	hl_bytes_blit(r6,r4,r8,r5,r14);
	r12 = r0->bytes;
	r13 = 3;
	r13 = r1 << r13;
	*(double*)(r12 + r13) = r2;
	return;
}

bool hl_types_ArrayBytes_Float_contains(hl__types__ArrayBytes_Float r0,double r1) {
	bool r2;
	vdynamic *r4;
	int r3, r5;
	r4 = NULL;
	r3 = hl_types_ArrayBytes_Float_indexOf(r0,r1,r4);
	r5 = -1;
	if( r3 != r5 ) goto label$d05ef5b_16_6;
	r2 = false;
	goto label$d05ef5b_16_7;
	label$d05ef5b_16_6:
	r2 = true;
	label$d05ef5b_16_7:
	return r2;
}

bool hl_types_ArrayBytes_Float_remove(hl__types__ArrayBytes_Float r0,double r1) {
	bool r7;
	vdynamic *r3;
	vbyte *r8, *r9, *r10, *r11, *r13;
	int r2, r5, r6, r12, r14, r15;
	r3 = NULL;
	r2 = hl_types_ArrayBytes_Float_indexOf(r0,r1,r3);
	r6 = 0;
	if( r2 >= r6 ) goto label$d05ef5b_17_6;
	r7 = false;
	return r7;
	label$d05ef5b_17_6:
	r5 = r0->length;
	--r5;
	r0->length = r5;
	r8 = r0->bytes;
	r9 = r0->bytes;
	r6 = 3;
	r5 = r2 << r6;
	r10 = r0->bytes;
	r11 = r0->bytes;
	r12 = 1;
	r6 = r2 + r12;
	r12 = 3;
	r6 = r6 << r12;
	r13 = r0->bytes;
	r14 = r0->length;
	r14 = r14 - r2;
	r15 = 3;
	r14 = r14 << r15;
	hl_bytes_blit(r8,r5,r10,r6,r14);
	r7 = true;
	return r7;
}

int hl_types_ArrayBytes_Float_indexOf(hl__types__ArrayBytes_Float r0,double r1,vdynamic* r2) {
	double r8;
	vbyte *r7;
	int r3, r4, r5, r6, r9;
	if( r2 ) goto label$d05ef5b_18_3;
	r3 = 0;
	goto label$d05ef5b_18_4;
	label$d05ef5b_18_3:
	r3 = r2 ? r2->v.i : 0;
	label$d05ef5b_18_4:
	r5 = 0;
	if( r3 >= r5 ) goto label$d05ef5b_18_13;
	r5 = r0->length;
	r4 = r3 + r5;
	r3 = r4;
	r5 = 0;
	if( r4 >= r5 ) goto label$d05ef5b_18_13;
	r4 = 0;
	r3 = r4;
	label$d05ef5b_18_13:
	r4 = r3;
	r5 = r0->length;
	label$d05ef5b_18_15:
	if( r4 >= r5 ) goto label$d05ef5b_18_26;
	r6 = r4;
	++r4;
	r7 = r0->bytes;
	r9 = 3;
	r9 = r6 << r9;
	r8 = *(double*)(r7 + r9);
	if( r8 != r1 ) goto label$d05ef5b_18_25;
	return r6;
	label$d05ef5b_18_25:
	goto label$d05ef5b_18_15;
	label$d05ef5b_18_26:
	r4 = -1;
	return r4;
}

int hl_types_ArrayBytes_Float_lastIndexOf(hl__types__ArrayBytes_Float r0,double r1,vdynamic* r2) {
	double r8;
	vbyte *r7;
	int r3, r4, r5, r6;
	r3 = r0->length;
	if( !r2 ) goto label$d05ef5b_19_4;
	r4 = r2 ? r2->v.i : 0;
	goto label$d05ef5b_19_6;
	label$d05ef5b_19_4:
	r5 = 1;
	r4 = r3 - r5;
	label$d05ef5b_19_6:
	if( r4 < r3 ) goto label$d05ef5b_19_11;
	r6 = 1;
	r5 = r3 - r6;
	r4 = r5;
	goto label$d05ef5b_19_15;
	label$d05ef5b_19_11:
	r6 = 0;
	if( r4 >= r6 ) goto label$d05ef5b_19_15;
	r5 = r4 + r3;
	r4 = r5;
	label$d05ef5b_19_15:
	r6 = 0;
	if( r4 < r6 ) goto label$d05ef5b_19_26;
	r7 = r0->bytes;
	r6 = 3;
	r6 = r4 << r6;
	r8 = *(double*)(r7 + r6);
	if( r8 != r1 ) goto label$d05ef5b_19_24;
	return r4;
	label$d05ef5b_19_24:
	--r4;
	goto label$d05ef5b_19_15;
	label$d05ef5b_19_26:
	r5 = -1;
	return r5;
}

hl__types__ArrayBytes_Float hl_types_ArrayBytes_Float_copy(hl__types__ArrayBytes_Float r0) {
	hl__types__ArrayBytes_Float r1;
	vbyte *r4, *r5, *r7, *r8;
	int r3, r6, r9, r10;
	r1 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r1);
	r3 = r0->length;
	r1->size = r3;
	r1->length = r3;
	r4 = r0->bytes;
	r3 = r0->length;
	r6 = 3;
	r3 = r3 << r6;
	r5 = hl_alloc_bytes(r3);
	r1->bytes = r5;
	r5 = r0->bytes;
	r7 = r1->bytes;
	r3 = 0;
	r8 = r0->bytes;
	r6 = 0;
	r9 = r0->length;
	r10 = 3;
	r9 = r9 << r10;
	hl_bytes_blit(r7,r3,r8,r6,r9);
	return r1;
}

haxe__iterators__ArrayIterator hl_types_ArrayBytes_Float_iterator(hl__types__ArrayBytes_Float r0) {
	hl__types__BytesIterator_Float r1;
	r1 = (hl__types__BytesIterator_Float)hl_alloc_obj(&t$hl_types_BytesIterator_Float);
	hl_types_BytesIterator_Float_new(r1,r0);
	return ((haxe__iterators__ArrayIterator)r1);
}

haxe__iterators__ArrayKeyValueIterator hl_types_ArrayBytes_Float_keyValueIterator(hl__types__ArrayBytes_Float r0) {
	haxe__iterators__ArrayKeyValueIterator r1;
	hl__types__ArrayDyn r2;
	r1 = (haxe__iterators__ArrayKeyValueIterator)hl_alloc_obj(&t$haxe_iterators_ArrayKeyValueIterator);
	r2 = (hl__types__ArrayDyn)hl_dyn_castp(&r0,&t$hl_types_ArrayBytes_Float,&t$hl_types_ArrayDyn);
	haxe_iterators_ArrayKeyValueIterator_new(r1,r2);
	return r1;
}

hl__types__ArrayDyn hl_types_ArrayBytes_Float_map(hl__types__ArrayBytes_Float r0,vclosure* r1) {
	bool *r14;
	hl__types__ArrayObj r2;
	bool r13;
	hl__types__ArrayDyn r12;
	double r10;
	vdynamic *r9;
	vbyte *r8;
	varray *r7;
	int r4, r5, r6, r11;
	r2 = (hl__types__ArrayObj)hl_alloc_obj(&t$hl_types_ArrayObj);
	hl_types_ArrayObj_new(r2);
	r4 = r0->length;
	r5 = 0;
	if( r5 >= r4 ) goto label$d05ef5b_23_9;
	r4 = r0->length;
	r5 = 1;
	r4 = r4 - r5;
	hl_types_ArrayObj___expand(r2,r4);
	label$d05ef5b_23_9:
	r4 = 0;
	r5 = r0->length;
	label$d05ef5b_23_11:
	if( r4 >= r5 ) goto label$d05ef5b_23_25;
	r6 = r4;
	++r4;
	if( r2 == NULL ) hl_null_access();
	r7 = r2->array;
	r8 = r0->bytes;
	if( r1 == NULL ) hl_null_access();
	r11 = 3;
	r11 = r6 << r11;
	r10 = *(double*)(r8 + r11);
	r9 = r1->hasValue ? ((vdynamic* (*)(vdynamic*,double))r1->fun)((vdynamic*)r1->value,r10) : ((vdynamic* (*)(double))r1->fun)(r10);
	((vdynamic**)(r7 + 1))[r6] = r9;
	goto label$d05ef5b_23_11;
	label$d05ef5b_23_25:
	r13 = true;
	r14 = &r13;
	r12 = hl_types_ArrayDyn_alloc(((hl__types__ArrayBase)r2),r14);
	return r12;
}

hl__types__ArrayBytes_Float hl_types_ArrayBytes_Float_filter(hl__types__ArrayBytes_Float r0,vclosure* r1) {
	bool r11;
	hl__types__ArrayBytes_Float r2;
	double r9;
	vbyte *r8;
	int r4, r5, r6, r7, r10;
	r2 = (hl__types__ArrayBytes_Float)hl_alloc_obj(&t$hl_types_ArrayBytes_Float);
	hl_types_ArrayBytes_Float_new(r2);
	r4 = 0;
	r5 = r0->length;
	label$d05ef5b_24_4:
	if( r4 >= r5 ) goto label$d05ef5b_24_18;
	r6 = r4;
	++r4;
	r8 = r0->bytes;
	r10 = 3;
	r10 = r6 << r10;
	r9 = *(double*)(r8 + r10);
	if( r1 == NULL ) hl_null_access();
	r11 = r1->hasValue ? ((bool (*)(vdynamic*,double))r1->fun)((vdynamic*)r1->value,r9) : ((bool (*)(double))r1->fun)(r9);
	if( !r11 ) goto label$d05ef5b_24_17;
	if( r2 == NULL ) hl_null_access();
	r7 = hl_types_ArrayBytes_Float_push(r2,r9);
	label$d05ef5b_24_17:
	goto label$d05ef5b_24_4;
	label$d05ef5b_24_18:
	return r2;
}

void hl_types_ArrayBytes_Float_resize(hl__types__ArrayBytes_Float r0,int r1) {
	vbyte *r5, *r6, *r7;
	int r3, r4, r8, r9;
	r3 = r0->length;
	if( r3 >= r1 ) goto label$d05ef5b_25_6;
	r4 = 1;
	r3 = r1 - r4;
	hl_types_ArrayBytes_Float___expand(r0,r3);
	goto label$d05ef5b_25_20;
	label$d05ef5b_25_6:
	r3 = r0->length;
	if( r1 >= r3 ) goto label$d05ef5b_25_20;
	r5 = r0->bytes;
	r6 = r0->bytes;
	r4 = 3;
	r3 = r1 << r4;
	r7 = r0->bytes;
	r8 = r0->length;
	r8 = r8 - r1;
	r9 = 3;
	r8 = r8 << r9;
	r9 = 0;
	hl_bytes_fill(r5,r3,r8,r9);
	r0->length = r1;
	label$d05ef5b_25_20:
	return;
}

vdynamic* hl_types_ArrayBytes_Float_getDyn(hl__types__ArrayBytes_Float r0,int r1) {
	double r4;
	vdynamic *r5;
	vbyte *r3;
	int r2;
	r2 = r0->length;
	if( r1 < r2 ) goto label$d05ef5b_26_6;
	r3 = r0->bytes;
	r4 = 0.;
	r5 = hl_alloc_dynamic(&t$_f64);
	r5->v.d = r4;
	return r5;
	label$d05ef5b_26_6:
	r3 = r0->bytes;
	r2 = 3;
	r2 = r1 << r2;
	r4 = *(double*)(r3 + r2);
	r5 = hl_alloc_dynamic(&t$_f64);
	r5->v.d = r4;
	return r5;
}

void hl_types_ArrayBytes_Float_setDyn(hl__types__ArrayBytes_Float r0,int r1,vdynamic* r2) {
	double r6;
	vbyte *r5;
	int r4;
	r4 = r0->length;
	if( r1 < r4 ) goto label$d05ef5b_27_3;
	hl_types_ArrayBytes_Float___expand(r0,r1);
	label$d05ef5b_27_3:
	r5 = r0->bytes;
	r6 = (double)hl_dyn_castd(&r2,&t$_dyn);
	r4 = 3;
	r4 = r1 << r4;
	*(double*)(r5 + r4) = r6;
	return;
}

int hl_types_ArrayBytes_Float_pushDyn(hl__types__ArrayBytes_Float r0,vdynamic* r1) {
	double r3;
	int r2;
	r3 = (double)hl_dyn_castd(&r1,&t$_dyn);
	r2 = hl_types_ArrayBytes_Float_push(r0,r3);
	return r2;
}

vdynamic* hl_types_ArrayBytes_Float_popDyn(hl__types__ArrayBytes_Float r0) {
	vdynamic *r1;
	r1 = hl_types_ArrayBytes_Float_pop(r0);
	return ((vdynamic*)r1);
}

vdynamic* hl_types_ArrayBytes_Float_shiftDyn(hl__types__ArrayBytes_Float r0) {
	vdynamic *r1;
	r1 = hl_types_ArrayBytes_Float_shift(r0);
	return ((vdynamic*)r1);
}

void hl_types_ArrayBytes_Float_unshiftDyn(hl__types__ArrayBytes_Float r0,vdynamic* r1) {
	double r3;
	r3 = (double)hl_dyn_castd(&r1,&t$_dyn);
	hl_types_ArrayBytes_Float_unshift(r0,r3);
	return;
}

void hl_types_ArrayBytes_Float_insertDyn(hl__types__ArrayBytes_Float r0,int r1,vdynamic* r2) {
	double r4;
	r4 = (double)hl_dyn_castd(&r2,&t$_dyn);
	hl_types_ArrayBytes_Float_insert(r0,r1,r4);
	return;
}

bool hl_types_ArrayBytes_Float_containsDyn(hl__types__ArrayBytes_Float r0,vdynamic* r1) {
	bool r2;
	double r3;
	r3 = (double)hl_dyn_castd(&r1,&t$_dyn);
	r2 = hl_types_ArrayBytes_Float_contains(r0,r3);
	return r2;
}

bool hl_types_ArrayBytes_Float_removeDyn(hl__types__ArrayBytes_Float r0,vdynamic* r1) {
	bool r2;
	double r3;
	r3 = (double)hl_dyn_castd(&r1,&t$_dyn);
	r2 = hl_types_ArrayBytes_Float_remove(r0,r3);
	return r2;
}

void hl_types_ArrayBytes_Float_sortDyn(hl__types__ArrayBytes_Float r0,vclosure* r1) {
	vclosure *r3;
	if( r1 ) goto label$d05ef5b_35_3;
	r3 = NULL;
	goto label$d05ef5b_35_4;
	label$d05ef5b_35_3:
	r3 = hl_alloc_closure_ptr(&t$fun_cae6940,hl_types_ArrayBytes_Float_sortDyn__$1,r1);
	label$d05ef5b_35_4:
	hl_types_ArrayBytes_Float_sort(r0,r3);
	return;
}

void hl_types_ArrayBytes_Float___expand(hl__types__ArrayBytes_Float r0,int r1) {
	String r5, r8;
	int *r6;
	vbyte *r7, *r11, *r12, *r13, *r14;
	int r3, r4, r9, r10, r15, r16;
	r4 = 0;
	if( r1 >= r4 ) goto label$d05ef5b_36_9;
	r5 = (String)s$Invalid_array_index_;
	r3 = r1;
	r6 = &r3;
	r7 = hl_itos(r3,r6);
	r8 = String___alloc__(r7,r3);
	r5 = String___add__(r5,r8);
	hl_throw((vdynamic*)r5);
	label$d05ef5b_36_9:
	r4 = 1;
	r3 = r1 + r4;
	r9 = r0->size;
	if( r9 >= r3 ) goto label$d05ef5b_36_40;
	r4 = r0->size;
	r9 = 3;
	r4 = r4 * r9;
	r9 = 1;
	r4 = r4 >> r9;
	if( r4 >= r3 ) goto label$d05ef5b_36_20;
	r4 = r3;
	label$d05ef5b_36_20:
	r7 = r0->bytes;
	r10 = 3;
	r9 = r4 << r10;
	r11 = hl_alloc_bytes(r9);
	r12 = r0->bytes;
	r9 = r0->length;
	r10 = 3;
	r9 = r9 << r10;
	r10 = 0;
	r14 = r0->bytes;
	r15 = 0;
	hl_bytes_blit(r11,r10,r14,r15,r9);
	r13 = r0->bytes;
	r16 = 3;
	r15 = r4 << r16;
	r15 = r15 - r9;
	r16 = 0;
	hl_bytes_fill(r11,r9,r15,r16);
	r0->bytes = r11;
	r0->size = r4;
	label$d05ef5b_36_40:
	r0->length = r3;
	return;
}
