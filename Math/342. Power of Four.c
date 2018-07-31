/*
342. Power of Four
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// #define A342
#ifdef A342

bool isPowerOfFour(int num) {
	return (num > 0 && (0x55555555 & num) != 0 && (num &(num - 1)) == 0);
}

int main(){
	for (int i = 0; i < 100; i++){
		printf("%d, %d\n", i, isPowerOfFour(i));
	}
	getchar();
	return 0;
}

#endif