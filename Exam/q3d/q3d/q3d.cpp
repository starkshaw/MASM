// q3d.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
using namespace System;

void run(void);

void run() {
	float X=1.0, Y=6.0, Z=3.0, R=0.0;
	unsigned short cntrl = 0x3FF, stat;

	_asm{
		FINIT
		FLDCW cntrl
		FLD X
		FLD Y
		FADD ST(0), ST(1)
		FLD Z
		FMUL ST(0), ST(0)
		FADD ST(0), ST(1)
		FSQRT
		FSTP R
	}
	printf("Decimal: %f\n", R);
}

int main(array<System::String ^> ^args)
{
    run();
    return 0;
}
