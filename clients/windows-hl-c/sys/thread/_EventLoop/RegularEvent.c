﻿// Generated by HLC 4.3.4 (HL v5)
#define HLC_BOOT
#include <hlc.h>
#include <sys/thread/_EventLoop/RegularEvent.h>

void sys_thread__EventLoop_RegularEvent_new(sys__thread___EventLoop__RegularEvent r0,vclosure* r1,double r2,double r3) {
	bool r4;
	r4 = false;
	r0->cancelled = r4;
	r0->run = r1;
	r0->nextRunTime = r2;
	r0->interval = r3;
	return;
}

