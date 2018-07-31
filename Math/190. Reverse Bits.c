/*
190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
Follow up:
If this function is called many times, how would you optimize it?
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A190
#ifdef A190

unsigned int reverseBits(unsigned int n) {
	unsigned int nums[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	unsigned int temp = 0 , x= n;
	for (int i = 0; i < 8; i++){
		temp = (temp << 4) + nums[x & 0x0F];
		x = x >> 4;
	}
	return temp;
}

int main(){
	for (unsigned int i = 0; i < 5; i++){
		printf("%d, %u\n", i, reverseBits(43261596));
	}
	getchar();
	return 0;
}

#endif