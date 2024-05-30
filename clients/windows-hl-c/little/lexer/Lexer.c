﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <little/lexer/Lexer.h>
#include <little/lexer/LexerTokens.h>
#include <little/KeywordConfig.h>
#include <_std/EReg.h>
extern hl_type t$little_lexer_LexerTokens;
#include <hl/natives.h>
hl__types__ArrayObj hl_types_ArrayObj_alloc(varray*);
String String_charAt(String,int);
extern hl_type t$_i32;
String String_substr(String,int,vdynamic*);
extern String s$b15835f;
extern String s$;
String little_tools_TextTools_replace(String,String,String);
String String___add__(String,String);
extern String s$68b329d;
int String___compare(String,vdynamic*);
extern venum* g$little_lexer_LexerTokens_Newline;
int hl_types_ArrayObj_push(hl__types__ArrayObj,vdynamic*);
extern String s$8b0f0ea;
extern String s$fa5881a;
String StringTools_trim(String);
extern String s$1234567890_;
bool little_tools_TextTools_contains(String,String);
extern String s$5058f1a;
bool StringTools_endsWith(String,String);
String little_tools_TextTools_replaceLast(String,String,String);
extern String s$9eecb7d;
extern String s$c0cb5f0;
extern venum* g$224c643;
extern little__$KeywordConfig g$_little_KeywordConfig;
bool hl_types_ArrayObj_contains(hl__types__ArrayObj,vdynamic*);
extern hl_type t$EReg;
extern String s$bd4e2a1;
String hl_types_ArrayObj_join(hl__types__ArrayObj,String);
extern String s$_t_n_r_;
extern String s$g;
void EReg_new(EReg,String,String);
bool EReg_match(EReg,String);
hl__types__ArrayObj little_lexer_Lexer_separateBooleanIdentifiers(hl__types__ArrayObj);
hl__types__ArrayObj little_lexer_Lexer_mergeOrSplitKnownSigns(hl__types__ArrayObj);
#include <little/Little.h>
#include <hl/types/ArrayDyn.h>
extern hl_type t$_dyn;
extern little__$Little g$_little_Little;
hl__types__ArrayDyn Type_enumParameters(vdynamic*);
extern hl_type t$String;
extern venum* g$a078821;
hl__types__ArrayObj hl_types_ArrayObj_concat(hl__types__ArrayObj,hl__types__ArrayObj);
hl__types__ArrayObj little_tools_TextTools_sortByLength(hl__types__ArrayObj);
void hl_types_ArrayObj_reverse(hl__types__ArrayObj);
bool StringTools_startsWith(String,String);
String String_substring(String,int,vdynamic*);

hl__types__ArrayObj little_lexer_Lexer_lex(String r0) {
	String r8, r9, r12, r13, r15;
	hl__types__ArrayObj r1, r17;
	venum *r18;
	hl_type *r3;
	bool r19;
	EReg r21;
	little__$KeywordConfig r20;
	vdynamic *r11;
	int r4, r6, r7, r10, r14, r16;
	varray *r2;
	r3 = &t$little_lexer_LexerTokens;
	r4 = 0;
	r2 = hl_alloc_array(r3,r4);
	r1 = hl_types_ArrayObj_alloc(r2);
	r4 = 0;
	label$3e05b2c_1_5:
	if( r0 == NULL ) hl_null_access();
	r7 = r0->length;
	if( r4 >= r7 ) goto label$3e05b2c_1_227;
	r8 = String_charAt(r0,r4);
	r7 = r0->length;
	r10 = 2;
	r7 = r7 - r10;
	if( r4 >= r7 ) goto label$3e05b2c_1_77;
	r7 = 3;
	r11 = hl_alloc_dynamic(&t$_i32);
	r11->v.i = r7;
	r9 = String_substr(r0,r4,r11);
	r12 = (String)s$b15835f;
	r13 = (String)s$;
	r9 = little_tools_TextTools_replace(r9,r12,r13);
	if( r9 == NULL ) hl_null_access();
	r6 = r9->length;
	r7 = 0;
	if( r6 != r7 ) goto label$3e05b2c_1_77;
	r9 = (String)s$;
	r6 = 0;
	r10 = 3;
	r7 = r4 + r10;
	r4 = r7;
	label$3e05b2c_1_29:
	if( r0 == NULL ) hl_null_access();
	r10 = r0->length;
	r14 = 2;
	r10 = r10 - r14;
	if( r4 >= r10 ) goto label$3e05b2c_1_54;
	r10 = 3;
	r11 = hl_alloc_dynamic(&t$_i32);
	r11->v.i = r10;
	r12 = String_substr(r0,r4,r11);
	r13 = (String)s$b15835f;
	r15 = (String)s$;
	r12 = little_tools_TextTools_replace(r12,r13,r15);
	if( r12 == NULL ) hl_null_access();
	r7 = r12->length;
	r10 = 0;
	if( r7 == r10 ) goto label$3e05b2c_1_54;
	r13 = String_charAt(r0,r4);
	r12 = String___add__(r9,r13);
	r9 = r12;
	r12 = String_charAt(r0,r4);
	r13 = (String)s$68b329d;
	if( r12 != r13 && (!r12 || !r13 || String___compare(r12,(vdynamic*)r13) != 0) ) goto label$3e05b2c_1_52;
	++r6;
	label$3e05b2c_1_52:
	++r4;
	goto label$3e05b2c_1_29;
	label$3e05b2c_1_54:
	r10 = 2;
	r7 = r4 + r10;
	r4 = r7;
	r7 = 0;
	r10 = r6;
	label$3e05b2c_1_59:
	if( r7 >= r10 ) goto label$3e05b2c_1_66;
	++r7;
	if( r1 == NULL ) hl_null_access();
	r18 = (venum*)g$little_lexer_LexerTokens_Newline;
	r16 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_59;
	label$3e05b2c_1_66:
	if( r1 == NULL ) hl_null_access();
	r13 = (String)s$8b0f0ea;
	r15 = (String)s$68b329d;
	r12 = little_tools_TextTools_replace(r9,r13,r15);
	r13 = (String)s$fa5881a;
	r15 = (String)s$68b329d;
	r12 = little_tools_TextTools_replace(r12,r13,r15);
	r12 = StringTools_trim(r12);
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,8);
	((little_lexer_LexerTokens_Documentation*)r18)->p0 = r12;
	r7 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_225;
	label$3e05b2c_1_77:
	r12 = (String)s$b15835f;
	if( r8 != r12 && (!r8 || !r12 || String___compare(r8,(vdynamic*)r12) != 0) ) goto label$3e05b2c_1_97;
	r9 = (String)s$;
	++r4;
	label$3e05b2c_1_81:
	if( r0 == NULL ) hl_null_access();
	r7 = r0->length;
	if( r4 >= r7 ) goto label$3e05b2c_1_93;
	r12 = String_charAt(r0,r4);
	r13 = (String)s$b15835f;
	if( r12 == r13 || (r12 && r13 && String___compare(r12,(vdynamic*)r13) == 0) ) goto label$3e05b2c_1_93;
	r13 = String_charAt(r0,r4);
	r12 = String___add__(r9,r13);
	r9 = r12;
	++r4;
	goto label$3e05b2c_1_81;
	label$3e05b2c_1_93:
	if( r1 == NULL ) hl_null_access();
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,4);
	((little_lexer_LexerTokens_Characters*)r18)->p0 = r9;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_225;
	label$3e05b2c_1_97:
	r9 = (String)s$1234567890_;
	r19 = little_tools_TextTools_contains(r9,r8);
	if( !r19 ) goto label$3e05b2c_1_140;
	r9 = r8;
	++r4;
	label$3e05b2c_1_102:
	if( r0 == NULL ) hl_null_access();
	r7 = r0->length;
	if( r4 >= r7 ) goto label$3e05b2c_1_115;
	r12 = (String)s$1234567890_;
	r13 = String_charAt(r0,r4);
	r19 = little_tools_TextTools_contains(r12,r13);
	if( !r19 ) goto label$3e05b2c_1_115;
	r13 = String_charAt(r0,r4);
	r12 = String___add__(r9,r13);
	r9 = r12;
	++r4;
	goto label$3e05b2c_1_102;
	label$3e05b2c_1_115:
	--r4;
	r13 = (String)s$5058f1a;
	if( r9 != r13 && (!r9 || !r13 || String___compare(r9,(vdynamic*)r13) != 0) ) goto label$3e05b2c_1_123;
	if( r1 == NULL ) hl_null_access();
	r12 = (String)s$5058f1a;
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,1);
	((little_lexer_LexerTokens_Sign*)r18)->p0 = r12;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_139;
	label$3e05b2c_1_123:
	r13 = (String)s$5058f1a;
	r19 = StringTools_endsWith(r9,r13);
	if( !r19 ) goto label$3e05b2c_1_136;
	if( r1 == NULL ) hl_null_access();
	r13 = (String)s$5058f1a;
	r15 = (String)s$;
	r12 = little_tools_TextTools_replaceLast(r9,r13,r15);
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,2);
	((little_lexer_LexerTokens_Number*)r18)->p0 = r12;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	r12 = (String)s$5058f1a;
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,1);
	((little_lexer_LexerTokens_Sign*)r18)->p0 = r12;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_139;
	label$3e05b2c_1_136:
	if( r1 == NULL ) hl_null_access();
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,2);
	((little_lexer_LexerTokens_Number*)r18)->p0 = r9;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	label$3e05b2c_1_139:
	goto label$3e05b2c_1_225;
	label$3e05b2c_1_140:
	r12 = (String)s$68b329d;
	if( r8 != r12 && (!r8 || !r12 || String___compare(r8,(vdynamic*)r12) != 0) ) goto label$3e05b2c_1_146;
	if( r1 == NULL ) hl_null_access();
	r18 = (venum*)g$little_lexer_LexerTokens_Newline;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_225;
	label$3e05b2c_1_146:
	r12 = (String)s$9eecb7d;
	if( r8 == r12 || (r8 && r12 && String___compare(r8,(vdynamic*)r12) == 0) ) goto label$3e05b2c_1_150;
	r12 = (String)s$c0cb5f0;
	if( r8 != r12 && (!r8 || !r12 || String___compare(r8,(vdynamic*)r12) != 0) ) goto label$3e05b2c_1_154;
	label$3e05b2c_1_150:
	if( r1 == NULL ) hl_null_access();
	r18 = (venum*)g$224c643;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_225;
	label$3e05b2c_1_154:
	r20 = (little__$KeywordConfig)g$_little_KeywordConfig;
	r17 = r20->recognizedOperators;
	if( r17 == NULL ) hl_null_access();
	r19 = hl_types_ArrayObj_contains(r17,((vdynamic*)r8));
	if( !r19 ) goto label$3e05b2c_1_181;
	r9 = r8;
	++r4;
	label$3e05b2c_1_161:
	if( r0 == NULL ) hl_null_access();
	r7 = r0->length;
	if( r4 >= r7 ) goto label$3e05b2c_1_176;
	r20 = (little__$KeywordConfig)g$_little_KeywordConfig;
	r17 = r20->recognizedOperators;
	if( r17 == NULL ) hl_null_access();
	r12 = String_charAt(r0,r4);
	r19 = hl_types_ArrayObj_contains(r17,((vdynamic*)r12));
	if( !r19 ) goto label$3e05b2c_1_176;
	r13 = String_charAt(r0,r4);
	r12 = String___add__(r9,r13);
	r9 = r12;
	++r4;
	goto label$3e05b2c_1_161;
	label$3e05b2c_1_176:
	--r4;
	if( r1 == NULL ) hl_null_access();
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,1);
	((little_lexer_LexerTokens_Sign*)r18)->p0 = r9;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	goto label$3e05b2c_1_225;
	label$3e05b2c_1_181:
	r21 = (EReg)hl_alloc_obj(&t$EReg);
	r9 = (String)s$bd4e2a1;
	r20 = (little__$KeywordConfig)g$_little_KeywordConfig;
	r17 = r20->recognizedOperators;
	if( r17 == NULL ) hl_null_access();
	r12 = (String)s$;
	r12 = hl_types_ArrayObj_join(r17,r12);
	r9 = String___add__(r9,r12);
	r12 = (String)s$_t_n_r_;
	r9 = String___add__(r9,r12);
	r12 = (String)s$g;
	EReg_new(r21,r9,r12);
	r19 = EReg_match(r21,r8);
	if( !r19 ) goto label$3e05b2c_1_225;
	r9 = r8;
	++r4;
	label$3e05b2c_1_197:
	if( r0 == NULL ) hl_null_access();
	r7 = r0->length;
	if( r4 >= r7 ) goto label$3e05b2c_1_221;
	r21 = (EReg)hl_alloc_obj(&t$EReg);
	r12 = (String)s$bd4e2a1;
	r20 = (little__$KeywordConfig)g$_little_KeywordConfig;
	r17 = r20->recognizedOperators;
	if( r17 == NULL ) hl_null_access();
	r13 = (String)s$;
	r13 = hl_types_ArrayObj_join(r17,r13);
	r12 = String___add__(r12,r13);
	r13 = (String)s$_t_n_r_;
	r12 = String___add__(r12,r13);
	r13 = (String)s$g;
	EReg_new(r21,r12,r13);
	r12 = String_charAt(r0,r4);
	r19 = EReg_match(r21,r12);
	if( !r19 ) goto label$3e05b2c_1_221;
	r13 = String_charAt(r0,r4);
	r12 = String___add__(r9,r13);
	r9 = r12;
	++r4;
	goto label$3e05b2c_1_197;
	label$3e05b2c_1_221:
	--r4;
	if( r1 == NULL ) hl_null_access();
	r18 = hl_alloc_enum(&t$little_lexer_LexerTokens,0);
	((little_lexer_LexerTokens_Identifier*)r18)->p0 = r9;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r18));
	label$3e05b2c_1_225:
	++r4;
	goto label$3e05b2c_1_5;
	label$3e05b2c_1_227:
	r17 = little_lexer_Lexer_separateBooleanIdentifiers(r1);
	r17 = little_lexer_Lexer_mergeOrSplitKnownSigns(r17);
	return r17;
}

hl__types__ArrayObj little_lexer_Lexer_separateBooleanIdentifiers(hl__types__ArrayObj r0) {
	String r13;
	little__$Little r15;
	hl__types__ArrayObj r1, r5;
	venum *r8, *r10, *r12;
	hl_type *r3;
	bool r11;
	little__KeywordConfig r14;
	hl__types__ArrayDyn r16;
	vdynamic *r9;
	int r4, r6, r7;
	varray *r2;
	r3 = &t$little_lexer_LexerTokens;
	r4 = 0;
	r2 = hl_alloc_array(r3,r4);
	r1 = hl_types_ArrayObj_alloc(r2);
	r4 = 0;
	r5 = r0;
	label$3e05b2c_2_6:
	if( r5 == NULL ) hl_null_access();
	r7 = r5->length;
	if( r4 >= r7 ) goto label$3e05b2c_2_55;
	r7 = r5->length;
	if( ((unsigned)r4) < ((unsigned)r7) ) goto label$3e05b2c_2_14;
	r8 = NULL;
	goto label$3e05b2c_2_20;
	label$3e05b2c_2_14:
	r2 = r5->array;
	r9 = ((vdynamic**)(r2 + 1))[r4];
	r8 = (venum*)r9;
	r10 = (venum*)hl_dyn_castp(&r9,&t$_dyn,&t$little_lexer_LexerTokens);
	if( r8 == r10 ) goto label$3e05b2c_2_20;
	hl_assert();
	label$3e05b2c_2_20:
	++r4;
	if( r1 == NULL ) hl_null_access();
	r15 = (little__$Little)g$_little_Little;
	r14 = r15->keywords;
	if( r14 == NULL ) hl_null_access();
	r13 = r14->TRUE_VALUE;
	r12 = hl_alloc_enum(&t$little_lexer_LexerTokens,0);
	((little_lexer_LexerTokens_Identifier*)r12)->p0 = r13;
	r11 = hl_type_enum_eq(((vdynamic*)r8),((vdynamic*)r12));
	if( r11 ) goto label$3e05b2c_2_36;
	r15 = (little__$Little)g$_little_Little;
	r14 = r15->keywords;
	if( r14 == NULL ) hl_null_access();
	r13 = r14->FALSE_VALUE;
	r12 = hl_alloc_enum(&t$little_lexer_LexerTokens,0);
	((little_lexer_LexerTokens_Identifier*)r12)->p0 = r13;
	r11 = hl_type_enum_eq(((vdynamic*)r8),((vdynamic*)r12));
	if( !r11 ) goto label$3e05b2c_2_43;
	label$3e05b2c_2_36:
	r16 = Type_enumParameters(((vdynamic*)r8));
	if( r16 == NULL ) hl_null_access();
	r6 = 0;
	r9 = ((vdynamic* (*)(hl__types__ArrayDyn,int))r16->$type->vobj_proto[0])(r16,r6);
	r13 = (String)hl_dyn_castp(&r9,&t$_dyn,&t$String);
	r10 = hl_alloc_enum(&t$little_lexer_LexerTokens,3);
	((little_lexer_LexerTokens_Boolean*)r10)->p0 = r13;
	goto label$3e05b2c_2_53;
	label$3e05b2c_2_43:
	r15 = (little__$Little)g$_little_Little;
	r14 = r15->keywords;
	if( r14 == NULL ) hl_null_access();
	r13 = r14->NULL_VALUE;
	r12 = hl_alloc_enum(&t$little_lexer_LexerTokens,0);
	((little_lexer_LexerTokens_Identifier*)r12)->p0 = r13;
	r11 = hl_type_enum_eq(((vdynamic*)r8),((vdynamic*)r12));
	if( !r11 ) goto label$3e05b2c_2_52;
	r10 = (venum*)g$a078821;
	goto label$3e05b2c_2_53;
	label$3e05b2c_2_52:
	r10 = r8;
	label$3e05b2c_2_53:
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r10));
	goto label$3e05b2c_2_6;
	label$3e05b2c_2_55:
	return r1;
}

hl__types__ArrayObj little_lexer_Lexer_mergeOrSplitKnownSigns(hl__types__ArrayObj r0) {
	String r12, r16, r20;
	little__$Little r14;
	hl__types__ArrayObj r1, r8, r15;
	venum *r9, *r11;
	hl_type *r3;
	bool r17, r18;
	little__KeywordConfig r13;
	vdynamic *r10, *r21;
	int r4, r6, r7, r19;
	varray *r2;
	r3 = &t$little_lexer_LexerTokens;
	r4 = 0;
	r2 = hl_alloc_array(r3,r4);
	r1 = hl_types_ArrayObj_alloc(r2);
	r4 = 0;
	label$3e05b2c_3_5:
	if( r0 == NULL ) hl_null_access();
	r7 = r0->length;
	if( r4 >= r7 ) goto label$3e05b2c_3_100;
	r7 = r0->length;
	if( ((unsigned)r4) < ((unsigned)r7) ) goto label$3e05b2c_3_13;
	r9 = NULL;
	goto label$3e05b2c_3_19;
	label$3e05b2c_3_13:
	r2 = r0->array;
	r10 = ((vdynamic**)(r2 + 1))[r4];
	r9 = (venum*)r10;
	r11 = (venum*)hl_dyn_castp(&r10,&t$_dyn,&t$little_lexer_LexerTokens);
	if( r9 == r11 ) goto label$3e05b2c_3_19;
	hl_assert();
	label$3e05b2c_3_19:
	if( r9 == NULL ) hl_null_access();
	r6 = HL__ENUM_INDEX__(r9);
	r7 = 1;
	if( r6 != r7 ) goto label$3e05b2c_3_96;
	r12 = ((little_lexer_LexerTokens_Sign*)r9)->p0;
	r14 = (little__$Little)g$_little_Little;
	r13 = r14->keywords;
	if( r13 == NULL ) hl_null_access();
	r8 = r13->RECOGNIZED_SIGNS;
	if( r8 == NULL ) hl_null_access();
	r3 = &t$String;
	r6 = 1;
	r2 = hl_alloc_array(r3,r6);
	r14 = (little__$Little)g$_little_Little;
	r13 = r14->keywords;
	if( r13 == NULL ) hl_null_access();
	r16 = r13->PROPERTY_ACCESS_SIGN;
	r6 = 0;
	((String*)(r2 + 1))[r6] = r16;
	r15 = hl_types_ArrayObj_alloc(r2);
	r8 = hl_types_ArrayObj_concat(r8,r15);
	r8 = little_tools_TextTools_sortByLength(r8);
	if( r8 == NULL ) hl_null_access();
	hl_types_ArrayObj_reverse(r8);
	r17 = false;
	label$3e05b2c_3_44:
	if( r12 == NULL ) hl_null_access();
	r6 = r12->length;
	r7 = 0;
	if( r7 >= r6 ) goto label$3e05b2c_3_95;
	r18 = false;
	r17 = r18;
	r6 = 0;
	label$3e05b2c_3_52:
	if( r8 == NULL ) hl_null_access();
	r19 = r8->length;
	if( r6 >= r19 ) goto label$3e05b2c_3_82;
	r19 = r8->length;
	if( ((unsigned)r6) < ((unsigned)r19) ) goto label$3e05b2c_3_60;
	r16 = NULL;
	goto label$3e05b2c_3_66;
	label$3e05b2c_3_60:
	r2 = r8->array;
	r10 = ((vdynamic**)(r2 + 1))[r6];
	r16 = (String)r10;
	r20 = (String)hl_dyn_castp(&r10,&t$_dyn,&t$String);
	if( r16 == r20 || (r16 && r20 && String___compare(r16,(vdynamic*)r20) == 0) ) goto label$3e05b2c_3_66;
	hl_assert();
	label$3e05b2c_3_66:
	++r6;
	r18 = StringTools_startsWith(r12,r16);
	if( !r18 ) goto label$3e05b2c_3_81;
	if( r12 == NULL ) hl_null_access();
	if( r16 == NULL ) hl_null_access();
	r7 = r16->length;
	r21 = NULL;
	r20 = String_substring(r12,r7,r21);
	r12 = r20;
	if( r1 == NULL ) hl_null_access();
	r11 = hl_alloc_enum(&t$little_lexer_LexerTokens,1);
	((little_lexer_LexerTokens_Sign*)r11)->p0 = r16;
	r7 = hl_types_ArrayObj_push(r1,((vdynamic*)r11));
	r18 = true;
	r17 = r18;
	goto label$3e05b2c_3_82;
	label$3e05b2c_3_81:
	goto label$3e05b2c_3_52;
	label$3e05b2c_3_82:
	if( !r17 ) goto label$3e05b2c_3_84;
	goto label$3e05b2c_3_44;
	label$3e05b2c_3_84:
	if( r1 == NULL ) hl_null_access();
	if( r12 == NULL ) hl_null_access();
	r6 = 0;
	r16 = String_charAt(r12,r6);
	r11 = hl_alloc_enum(&t$little_lexer_LexerTokens,1);
	((little_lexer_LexerTokens_Sign*)r11)->p0 = r16;
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r11));
	r6 = 1;
	r21 = NULL;
	r16 = String_substring(r12,r6,r21);
	r12 = r16;
	goto label$3e05b2c_3_44;
	label$3e05b2c_3_95:
	goto label$3e05b2c_3_98;
	label$3e05b2c_3_96:
	if( r1 == NULL ) hl_null_access();
	r6 = hl_types_ArrayObj_push(r1,((vdynamic*)r9));
	label$3e05b2c_3_98:
	++r4;
	goto label$3e05b2c_3_5;
	label$3e05b2c_3_100:
	return r1;
}

