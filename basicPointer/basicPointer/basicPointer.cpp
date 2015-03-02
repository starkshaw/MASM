// basicPointer.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
using namespace System;

int main(array<System::String ^> ^args)
{
    int x=10;
	int *address;	// Initialize pointer
	int y=0;

	address=&x;		// Assign the pointer point to the value of x
	y=*address;		// Store the value which the pointer points into y

	printf("%d\n", y);

	int z[3]={5,7,11};
	address = &z[0];	// Assign the value of index 0 in z
	y=*(address+2);		// Pointer operation, add 2 units to the pointer, which point to 11
	printf("%d\n",y);

	while(getchar()!=10);
	while(getchar()!=10);
    return 0;
}
