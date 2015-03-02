// calc.cpp : main project file.

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
	/*unsigned short num1;
	unsigned short num2;
	unsigned short num3;
	unsigned short result;

	printf("A+B-C\n");
	printf("Enter first number: ");
	scanf("%hd", &num1);
	printf("Enter second number: ");
	scanf("%hd", &num2);
	printf("Enter third number: ");
	scanf("%hd", &num3);

	_asm{
		mov ax, num1;
		mov bx, num2;
		mov cx, num3;
		add ax, bx;
		sub ax, cx;
		mov result, ax;
	}

	printf("%hd", result);

	while(getchar()!=10);
	while(getchar()!=10);*/		// A + B - C

	//float SX=5.0, SY=12.0, HY=0.0;
	float SX=4.0, SY=9.0, HY=0.0;
	unsigned short cntrl=0x3FF, stat;

	_asm{
		FINIT;
		FLDCW cntrl;
		FLD SX;				// LOAD 4
		FMUL ST, ST(0);		// 4 * 4
		FLD SX;				// LOAD 4
		FMUL ST, ST(1);		// 4 * 16 = 64
		FLD SY;				// LOAD 9
		FSQRT;				// SQUARE ROOT 9 = 3
		FADD ST, ST(1);		// 64 + 3 = 67
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


