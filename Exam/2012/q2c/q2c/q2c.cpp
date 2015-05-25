// q2c.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>

using namespace System;

void run(void);

void run() {
	float SX = 5.0, SY = 12.0, HY = 0.0;
	unsigned short cntrl = 0x3FF, stat;

	_asm {
		FINIT
		FLDCW cntrl
		FLD SX			// Load SX = 5
		FMUL ST, ST(0)	// ST(0) = 5 * 5 = 25
		FLD SY			// Load SY = 12
		FMUL ST, ST(0)	// ST(0) = 12 * 12 = 144
		FADD ST, ST(1)	// ST(0) = 144 + 25 = 169
		FSQRT			// SQRT(169) = 13
		FSTSW stat
		FSTP HY
	}

	printf("Decimal: %f\n", HY);
}

int main(array<System::String ^> ^args)
{
    run();
    return 0;
}
