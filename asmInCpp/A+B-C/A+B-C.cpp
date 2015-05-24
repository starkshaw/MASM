// A+B-C.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>

using namespace System;

void test(void);

void test(){
	unsigned short num1;
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
		mov ax, num1;	// ax = num1
		mov bx, num2;	// bx = num2
		mov cx, num3;	// cx = num3
		add ax, bx;		// ax = ax + bx
		sub ax, cx;		// ax = cx - ax
		mov result, ax;
	}

	printf("%hd", result);

	while(getchar()!=10);
	while(getchar()!=10);
}

int main(array<System::String ^> ^args)
{
	test();
    return 0;
}
