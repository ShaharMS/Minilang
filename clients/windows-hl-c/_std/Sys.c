﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <_std/Sys.h>
extern $Sys g$_Sys;
#include <hl/natives.h>
String Std_string(vdynamic*);
extern String s$68b329d;
#include <sys/io/FileInput.h>
extern hl_type t$sys_io_FileInput;
void sys_io_FileInput_new(sys__io__FileInput,hl_fdesc*);
extern hl_type t$String;
String haxe_SysTools_quoteUnixArg(String);
extern hl_type t$fun_0cf7b0f;
extern String s$Windows;
int String___compare(String,vdynamic*);
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
extern String s$6666cd7;
extern String s$28d397e;
String StringTools_replace(String,String,String);
hl__types__ArrayObj hl_types_ArrayObj_concat(hl__types__ArrayObj,hl__types__ArrayObj);
extern hl_type t$_dyn;
String haxe_SysTools_quoteWinArg(String,bool);
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
extern String s$7215ee9;
String hl_types_ArrayObj_join(hl__types__ArrayObj,String);

vbyte* Sys_getPath(String r0) {
	$Sys r2;
	bool r1;
	int *r5;
	int r4;
	vbyte *r3;
	r2 = ($Sys)g$_Sys;
	r1 = r2->utf8Path;
	if( !r1 ) goto label$e42c1e8_1_9;
	if( r0 == NULL ) hl_null_access();
	r3 = r0->bytes;
	r4 = 0;
	r5 = NULL;
	r3 = hl_utf16_to_utf8(r3,r4,r5);
	return r3;
	label$e42c1e8_1_9:
	if( r0 == NULL ) hl_null_access();
	r3 = r0->bytes;
	return r3;
}

void Sys_print(vdynamic* r0) {
	String r3;
	vbyte *r2;
	r3 = Std_string(r0);
	if( r3 == NULL ) hl_null_access();
	r2 = r3->bytes;
	hl_sys_print(r2);
	return;
}

void Sys_println(vdynamic* r0) {
	String r3;
	vbyte *r2;
	r3 = Std_string(r0);
	if( r3 == NULL ) hl_null_access();
	r2 = r3->bytes;
	hl_sys_print(r2);
	r3 = (String)s$68b329d;
	if( r3 == NULL ) hl_null_access();
	r2 = r3->bytes;
	hl_sys_print(r2);
	return;
}

haxe__io__Input Sys_stdin() {
	hl_fdesc *r1;
	sys__io__FileInput r0;
	r0 = (sys__io__FileInput)hl_alloc_obj(&t$sys_io_FileInput);
	r1 = hl_file_stdin();
	sys_io_FileInput_new(r0,r1);
	return ((haxe__io__Input)r0);
}

String Sys_systemName() {
	String r1;
	int r2;
	vbyte *r0;
	r0 = hl_sys_string();
	r1 = (String)hl_alloc_obj(&t$String);
	r1->bytes = r0;
	r2 = 0;
	r2 = hl_ucs2length(r0,r2);
	r1->length = r2;
	return r1;
}

int Sys_command(String r0,hl__types__ArrayObj r1) {
	String r6, r7, r12;
	hl__types__ArrayObj r3, r10;
	hl_type *r9;
	bool r15;
	vclosure *r16;
	vdynamic *r14;
	varray *r8;
	vbyte *r5;
	int r2, r4, r11, r13;
	static vclosure cl$0 = { &t$fun_0cf7b0f, haxe_SysTools_quoteUnixArg, 0 };
	r2 = 0;
	if( r1 ) goto label$e42c1e8_6_5;
	r5 = Sys_getPath(r0);
	r4 = hl_sys_command(r5);
	goto label$e42c1e8_6_89;
	label$e42c1e8_6_5:
	r6 = Sys_systemName();
	r7 = (String)s$Windows;
	if( r6 != r7 && (!r6 || !r7 || String___compare(r6,(vdynamic*)r7) != 0) ) goto label$e42c1e8_6_50;
	r9 = &t$String;
	r4 = 0;
	r8 = hl_alloc_array(r9,r4);
	r3 = hl_types_ArrayObj_alloc(r8);
	r4 = 0;
	r9 = &t$String;
	r11 = 1;
	r8 = hl_alloc_array(r9,r11);
	r7 = (String)s$6666cd7;
	r12 = (String)s$28d397e;
	r6 = StringTools_replace(r0,r7,r12);
	r11 = 0;
	((String*)(r8 + 1))[r11] = r6;
	r10 = hl_types_ArrayObj_alloc(r8);
	if( r10 == NULL ) hl_null_access();
	r10 = hl_types_ArrayObj_concat(r10,r1);
	label$e42c1e8_6_24:
	if( r10 == NULL ) hl_null_access();
	r13 = r10->length;
	if( r4 >= r13 ) goto label$e42c1e8_6_44;
	r13 = r10->length;
	if( ((unsigned)r4) < ((unsigned)r13) ) goto label$e42c1e8_6_32;
	r6 = NULL;
	goto label$e42c1e8_6_38;
	label$e42c1e8_6_32:
	r8 = r10->array;
	r14 = ((vdynamic**)(r8 + 1))[r4];
	r6 = (String)r14;
	r7 = (String)hl_dyn_castp(&r14,&t$_dyn,&t$String);
	if( r6 == r7 || (r6 && r7 && String___compare(r6,(vdynamic*)r7) == 0) ) goto label$e42c1e8_6_38;
	hl_assert();
	label$e42c1e8_6_38:
	++r4;
	if( r3 == NULL ) hl_null_access();
	r15 = true;
	r7 = haxe_SysTools_quoteWinArg(r6,r15);
	r11 = hl_types_ArrayObj_push(r3,((vdynamic*)r7));
	goto label$e42c1e8_6_24;
	label$e42c1e8_6_44:
	if( r3 == NULL ) hl_null_access();
	r6 = (String)s$7215ee9;
	r6 = hl_types_ArrayObj_join(r3,r6);
	r5 = Sys_getPath(r6);
	r4 = hl_sys_command(r5);
	goto label$e42c1e8_6_89;
	label$e42c1e8_6_50:
	r16 = &cl$0;
	r9 = &t$String;
	r4 = 0;
	r8 = hl_alloc_array(r9,r4);
	r3 = hl_types_ArrayObj_alloc(r8);
	r4 = 0;
	r9 = &t$String;
	r11 = 1;
	r8 = hl_alloc_array(r9,r11);
	r11 = 0;
	((String*)(r8 + 1))[r11] = r0;
	r10 = hl_types_ArrayObj_alloc(r8);
	if( r10 == NULL ) hl_null_access();
	r10 = hl_types_ArrayObj_concat(r10,r1);
	label$e42c1e8_6_64:
	if( r10 == NULL ) hl_null_access();
	r13 = r10->length;
	if( r4 >= r13 ) goto label$e42c1e8_6_84;
	r13 = r10->length;
	if( ((unsigned)r4) < ((unsigned)r13) ) goto label$e42c1e8_6_72;
	r6 = NULL;
	goto label$e42c1e8_6_78;
	label$e42c1e8_6_72:
	r8 = r10->array;
	r14 = ((vdynamic**)(r8 + 1))[r4];
	r6 = (String)r14;
	r7 = (String)hl_dyn_castp(&r14,&t$_dyn,&t$String);
	if( r6 == r7 || (r6 && r7 && String___compare(r6,(vdynamic*)r7) == 0) ) goto label$e42c1e8_6_78;
	hl_assert();
	label$e42c1e8_6_78:
	++r4;
	if( r3 == NULL ) hl_null_access();
	if( r16 == NULL ) hl_null_access();
	r7 = r16->hasValue ? ((String (*)(vdynamic*,String))r16->fun)((vdynamic*)r16->value,r6) : ((String (*)(String))r16->fun)(r6);
	r11 = hl_types_ArrayObj_push(r3,((vdynamic*)r7));
	goto label$e42c1e8_6_64;
	label$e42c1e8_6_84:
	if( r3 == NULL ) hl_null_access();
	r6 = (String)s$7215ee9;
	r6 = hl_types_ArrayObj_join(r3,r6);
	r5 = Sys_getPath(r6);
	r4 = hl_sys_command(r5);
	label$e42c1e8_6_89:
	return r4;
}

