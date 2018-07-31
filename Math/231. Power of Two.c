/*
231. Power of Two
Given an integer, write a function to determine if it is a power of two.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A231
#ifdef A231

bool isPowerOfTwo(int n) {
	return (n > 0 && (n & (n - 1)) == 0);
}

int main(){
	for (int i = 0; i < 100; i++){
		printf("%d, %d\n", i, isPowerOfTwo(i));
	}
	getchar();
	return 0;
}

#endif