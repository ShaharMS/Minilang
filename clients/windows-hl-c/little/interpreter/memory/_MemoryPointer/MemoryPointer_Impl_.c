﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <little/interpreter/memory/_MemoryPointer/MemoryPointer_Impl_.h>
#include <hl/natives.h>
String String___alloc__(vbyte*,int);
extern String s$;
String String___add__(String,String);

int little_interpreter_memory__MemoryPointer_MemoryPointer_Impl___new(int r0) {
	return r0;
}

int little_interpreter_memory__MemoryPointer_MemoryPointer_Impl__fromInt(int r0) {
	int r1;
	r1 = little_interpreter_memory__MemoryPointer_MemoryPointer_Impl___new(r0);
	return r1;
}

String little_interpreter_memory__MemoryPointer_MemoryPointer_Impl__toString(int r0) {
	String r1, r5;
	int *r3;
	vbyte *r4;
	int r2;
	r2 = r0;
	r3 = &r2;
	r4 = hl_itos(r2,r3);
	r1 = String___alloc__(r4,r2);
	r5 = (String)s$;
	r1 = String___add__(r1,r5);
	return r1;
}

int little_interpreter_memory__MemoryPointer_MemoryPointer_Impl__toInt(int r0) {
	return r0;
}

