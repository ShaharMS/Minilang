﻿// Generated by HLC 4.3.4 (HL v5)
#ifndef INC_little__parser__Parser
#define INC_little__parser__Parser
typedef struct _little__parser__$Parser *little__parser__$Parser;
typedef struct _little__parser__Parser *little__parser__Parser;
#include <hl/Class.h>
#include <hl/BaseType.h>
#include <_std/String.h>
#include <hl/types/ArrayObj.h>


struct _little__parser__$Parser {
	hl_type *$type;
	hl_type* _hx___type__;
	vdynamic* _hx___meta__;
	varray* _hx___implementedBy__;
	String _hx___name__;
	vdynamic* _hx___constructor__;
	hl__types__ArrayObj additionalParsingLevels;
	vclosure* parse;
	vclosure* convert;
	vclosure* mergeBlocks;
	vclosure* mergeExpressions;
	vclosure* mergePropertyOperations;
	vclosure* mergeTypeDecls;
	vclosure* mergeComplexStructures;
	vclosure* mergeCalls;
	vclosure* mergeWrites;
	vclosure* mergeValuesWithTypeDecls;
	vclosure* mergeNonBlockBodies;
	vclosure* mergeElses;
	vclosure* get_line;
	vclosure* set_line;
	vclosure* get_module;
	vclosure* set_module;
	int linePart;
	vclosure* setLine;
	vclosure* nextPart;
	vclosure* resetLines;
};
struct _little__parser__Parser {
	hl_type *$type;
};
#endif
