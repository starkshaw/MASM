// q3d.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>

using namespace System;

void run(void);

void run() {
	// The following commented code is an instance of calculating 4 ^ 3 = 64
	/*float X = 4.0, R = 0.0;
	unsigned short cntrl = 0x3FF, stat;
	_asm {
		FINIT
		FLDCW cntrl
		FLD X
		FLD X
		FMUL ST(0), ST(0)
		FMUL ST(0), ST(1)
		FSTP R
	}
	printf("Answer: %f\n", R);*/
	float X = 3.0, Y = 2.0, Z = 0.0;
	unsigned short cntrl = 0x3FF, stat;
	_asm {
		FINIT
		FLDCW cntrl			// Load floating point control word
		FLD X				// Load X = 3
		FMUL ST(0), ST(0)	// ST(0) = 3 * 3 = 9
		FLD X				// Load X again
		FMUL ST(0), ST(1)	// ST(0) = 9 * 3 = 27
		FLD Y				// Load Y = 2
		FMUL ST(0), ST(0)	// ST(0) = 2 * 2 = 4
		FADD ST(0), ST(1)	// ST(0) = 4 + 27 = 31
		FADD ST(0), ST(0)	// ST(0) = 31 + 31 = 62
		FSTSW stat
		FSTP Z
	}
	printf("Decimal: %f\n", Z);
}

int main(array<System::String ^> ^args)
{
    run();
    return 0;
}
