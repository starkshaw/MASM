// FloatEval.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
using namespace System;

void test(void);

int main(array<System::String ^> ^args)
{
    test();
    return 0;
}

void test(){
	float SX=5.0, SY=12.0, HY=0.0;
	unsigned short cntrl=0x3FF, stat;

	_asm{
		FINIT;
		FLDCW cntrl;
		FLD SX;				// LOAD 5
		FMUL ST, ST(0);		// 5 * 5 = 25
		FLD SY;				// LOAD 12
		FMUL ST, ST(0);		// 12 * 12 = 144
		FADD ST, ST(1);		// 144 + 25 = 169
		FSQRT;				// SQRT(169) = 13
		FSTSW stat;
		FSTP HY;
	}

	printf("Decimal: %f\n", HY);
	printf("HEX: %4X\n", *((unsigned long *)&HY));
	printf("BIN: ");
	unsigned char byt;
	for(int x=3; x>=0; x--){
		byt=*((unsigned char *)&HY+x);
		for(int y=128;y>0;y/=2){
			if((y&byt)==0){
				printf("0");
			}else{
				printf("1");
			}
		}
	}
	printf("\n");

	while(getchar()!=10);
	while(getchar()!=10);
}


