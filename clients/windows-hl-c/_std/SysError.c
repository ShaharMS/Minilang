﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <_std/SysError.h>
String SysError_toString(SysError);
extern String s$SysError_;
String String___add__(String,String);
extern String s$9371d7a;

void SysError_new(SysError r0,String r1) {
	r0->msg = r1;
	return;
}

vbyte* SysError___string(SysError r0) {
	String r2;
	vbyte *r1;
	r2 = SysError_toString(r0);
	if( r2 == NULL ) hl_null_access();
	r1 = r2->bytes;
	return r1;
}

String SysError_toString(SysError r0) {
	String r1, r2;
	r1 = (String)s$SysError_;
	r2 = r0->msg;
	r1 = String___add__(r1,r2);
	r2 = (String)s$9371d7a;
	r1 = String___add__(r1,r2);
	return r1;
}

