﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_little__lexer__Lexer
#define INC_little__lexer__Lexer
typedef struct _little__lexer__$Lexer *little__lexer__$Lexer;
typedef struct _little__lexer__Lexer *little__lexer__Lexer;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayObj.h>


struct _little__lexer__$Lexer {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
	vclosure* lex;
	vclosure* separateBooleanIdentifiers;
	vclosure* mergeOrSplitKnownSigns;
};
struct _little__lexer__Lexer {
	hl_type *$type;
};
#endif

