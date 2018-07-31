/*
476. Number Complement
Given a positive integer, output its complement number.The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32 - bit signed integer.
You could assume no leading zero bit in the integer¡¯s binary representation.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A476
#ifdef A476

int findComplement(int num) {
	int temp = 0xFFFFFFFF;
	while ((temp & num) != 0)
	{
		temp = temp <<  1;
	}	
	return (~temp & 0x7FFFFFFF) ^ num;
}

int main(){
	printf("%d", findComplement(1));
	getchar();
	return 0;
}

#endif