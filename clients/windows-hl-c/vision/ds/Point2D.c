﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <vision/ds/Point2D.h>

void vision_ds_Point2D_new(vision__ds__Point2D r0,double* r1,double* r2) {
	double r3, r4;
	if( r1 ) goto label$a2e2b0b_1_3;
	r3 = 0.;
	goto label$a2e2b0b_1_4;
	label$a2e2b0b_1_3:
	r3 = *r1;
	label$a2e2b0b_1_4:
	if( r2 ) goto label$a2e2b0b_1_7;
	r4 = 0.;
	goto label$a2e2b0b_1_8;
	label$a2e2b0b_1_7:
	r4 = *r2;
	label$a2e2b0b_1_8:
	r0->x = r3;
	r0->y = r4;
	return;
}
