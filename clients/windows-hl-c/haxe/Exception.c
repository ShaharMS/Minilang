﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <haxe/Exception.h>
#include <haxe/ValueException.h>
extern haxe__$Exception g$_haxe_Exception;
bool Std_isOfType(vdynamic*,vdynamic*);
extern hl_type t$haxe_Exception;
extern hl_type t$_dyn;
extern hl_type t$haxe_ValueException;
void haxe_ValueException_new(haxe__ValueException,vdynamic*,haxe__Exception,vdynamic*);
String haxe_Exception_get_message(haxe__Exception);
haxe__Exception haxe_Exception_get_previous(haxe__Exception);
extern String s$Exception_;
String String___add__(String,String);
hl__types__ArrayObj haxe_Exception_get_stack(haxe__Exception);
extern String s$null;
String haxe__CallStack_CallStack_Impl__toString(hl__types__ArrayObj);
extern String s$;
hl__types__ArrayObj haxe__CallStack_CallStack_Impl__subtract(hl__types__ArrayObj,hl__types__ArrayObj);
extern String s$_Next_;
hl__types__ArrayObj haxe_NativeStackTrace_toHaxe(varray*,int*);
varray* haxe_NativeStackTrace_exceptionStack(void);
#include <hl/natives.h>
extern hl_type t$hl_symbol;

haxe__Exception haxe_Exception_caught(vdynamic* r0) {
	bool r2;
	haxe__$Exception r3;
	haxe__ValueException r5;
	haxe__Exception r4;
	int r6;
	r3 = (haxe__$Exception)g$_haxe_Exception;
	r2 = Std_isOfType(r0,((vdynamic*)r3));
	if( !r2 ) goto label$2937a61_1_5;
	r4 = (haxe__Exception)hl_dyn_castp(&r0,&t$_dyn,&t$haxe_Exception);
	return r4;
	label$2937a61_1_5:
	r5 = (haxe__ValueException)hl_alloc_obj(&t$haxe_ValueException);
	r4 = NULL;
	haxe_ValueException_new(r5,r0,r4,r0);
	r6 = r5->_hx___skipStack;
	--r6;
	r5->_hx___skipStack = r6;
	return ((haxe__Exception)r5);
}

vbyte* haxe_Exception___string(haxe__Exception r0) {
	String r2;
	vbyte *r1;
	r2 = ((String (*)(haxe__Exception))r0->$type->vobj_proto[0])(r0);
	if( r2 == NULL ) hl_null_access();
	r1 = r2->bytes;
	return r1;
}

String haxe_Exception_toString(haxe__Exception r0) {
	String r1;
	r1 = haxe_Exception_get_message(r0);
	return r1;
}

String haxe_Exception_details(haxe__Exception r0) {
	String r2, r3, r5, r9;
	hl__types__ArrayObj r4, r6;
	haxe__Exception r1, r7, r8;
	r1 = haxe_Exception_get_previous(r0);
	if( r1 ) goto label$2937a61_4_12;
	r2 = (String)s$Exception_;
	r3 = ((String (*)(haxe__Exception))r0->$type->vobj_proto[0])(r0);
	r2 = String___add__(r2,r3);
	r4 = haxe_Exception_get_stack(r0);
	if( r4 ) goto label$2937a61_4_9;
	r5 = (String)s$null;
	goto label$2937a61_4_10;
	label$2937a61_4_9:
	r5 = haxe__CallStack_CallStack_Impl__toString(r4);
	label$2937a61_4_10:
	r3 = String___add__(r2,r5);
	return r3;
	label$2937a61_4_12:
	r2 = (String)s$;
	r1 = r0;
	r7 = NULL;
	label$2937a61_4_15:
	if( !r1 ) goto label$2937a61_4_52;
	if( r7 ) goto label$2937a61_4_31;
	r3 = (String)s$Exception_;
	if( r1 == NULL ) hl_null_access();
	r5 = haxe_Exception_get_message(r1);
	r3 = String___add__(r3,r5);
	r4 = haxe_Exception_get_stack(r1);
	if( r4 ) goto label$2937a61_4_26;
	r9 = (String)s$null;
	goto label$2937a61_4_27;
	label$2937a61_4_26:
	r9 = haxe__CallStack_CallStack_Impl__toString(r4);
	label$2937a61_4_27:
	r5 = String___add__(r3,r9);
	r5 = String___add__(r5,r2);
	r2 = r5;
	goto label$2937a61_4_48;
	label$2937a61_4_31:
	if( r1 == NULL ) hl_null_access();
	r4 = haxe_Exception_get_stack(r1);
	if( r7 == NULL ) hl_null_access();
	r6 = haxe_Exception_get_stack(r7);
	r4 = haxe__CallStack_CallStack_Impl__subtract(r4,r6);
	r3 = (String)s$Exception_;
	r5 = haxe_Exception_get_message(r1);
	r3 = String___add__(r3,r5);
	if( r4 ) goto label$2937a61_4_42;
	r5 = (String)s$null;
	goto label$2937a61_4_43;
	label$2937a61_4_42:
	r5 = haxe__CallStack_CallStack_Impl__toString(r4);
	label$2937a61_4_43:
	r3 = String___add__(r3,r5);
	r5 = (String)s$_Next_;
	r3 = String___add__(r3,r5);
	r3 = String___add__(r3,r2);
	r2 = r3;
	label$2937a61_4_48:
	r7 = r1;
	r8 = haxe_Exception_get_previous(r1);
	r1 = r8;
	goto label$2937a61_4_15;
	label$2937a61_4_52:
	return r2;
}

void haxe_Exception___shiftStack(haxe__Exception r0) {
	int r1;
	r1 = r0->_hx___skipStack;
	++r1;
	r0->_hx___skipStack = r1;
	return;
}

void haxe_Exception___unshiftStack(haxe__Exception r0) {
	int r1;
	r1 = r0->_hx___skipStack;
	--r1;
	r0->_hx___skipStack = r1;
	return;
}

String haxe_Exception_get_message(haxe__Exception r0) {
	String r1;
	r1 = r0->_hx___exceptionMessage;
	return r1;
}

haxe__Exception haxe_Exception_get_previous(haxe__Exception r0) {
	haxe__Exception r1;
	r1 = r0->_hx___previousException;
	return r1;
}

hl__types__ArrayObj haxe_Exception_get_stack(haxe__Exception r0) {
	hl__types__ArrayObj r1, r2;
	int *r5;
	int r4;
	varray *r3;
	r1 = r0->_hx___exceptionStack;
	if( r1 ) goto label$2937a61_9_8;
	r3 = r0->_hx___nativeStack;
	r4 = r0->_hx___skipStack;
	r5 = &r4;
	r2 = haxe_NativeStackTrace_toHaxe(r3,r5);
	r0->_hx___exceptionStack = r2;
	return r2;
	label$2937a61_9_8:
	return r1;
}

void haxe_Exception_new(haxe__Exception r0,String r1,haxe__Exception r2,vdynamic* r3) {
	hl_type *r8;
	varray *r6, *r9, *r11;
	int r4, r7, r10, r12;
	r4 = 0;
	r0->_hx___skipStack = r4;
	r0->_hx___exceptionMessage = r1;
	r0->_hx___previousException = r2;
	if( !r3 ) goto label$2937a61_10_9;
	r6 = haxe_NativeStackTrace_exceptionStack();
	r0->_hx___nativeStack = r6;
	r0->_hx___nativeException = r3;
	goto label$2937a61_10_30;
	label$2937a61_10_9:
	r6 = NULL;
	r4 = hl_call_stack_raw(r6);
	r8 = &t$hl_symbol;
	r6 = hl_alloc_array(r8,r4);
	r7 = hl_call_stack_raw(r6);
	r7 = r6->size;
	r10 = 0;
	if( r7 != r10 ) goto label$2937a61_10_19;
	r9 = r6;
	goto label$2937a61_10_28;
	label$2937a61_10_19:
	r7 = r6->size;
	r10 = 1;
	r7 = r7 - r10;
	r8 = &t$hl_symbol;
	r11 = hl_alloc_array(r8,r7);
	r10 = 0;
	r12 = 1;
	hl_array_blit(r11,r10,r6,r12,r7);
	r9 = r11;
	label$2937a61_10_28:
	r0->_hx___nativeStack = r9;
	r0->_hx___nativeException = ((vdynamic*)r0);
	label$2937a61_10_30:
	return;
}
