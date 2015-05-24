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
		FLD X				// Load X = 1.0
		FLD Y				// Load Y = 6.0
		FADD ST(0), ST(1)	// ST(0) = 6 + 1 = 7
		FLD Z				// Load Z = 3.0
		FMUL ST(0), ST(0)	// ST(0) = 3 * 3 = 9
		FADD ST(0), ST(1)	// ST(0) = 9 + 7 = 16
		FSQRT				// SQRT(16) = 4
		FSTP R				// Floating Point Store to R
	}
	printf("Decimal: %f\n", R);
}

int main(array<System::String ^> ^args)
{
    run();
    return 0;
}
