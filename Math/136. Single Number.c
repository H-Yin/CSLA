/*
136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A136
#ifdef A136

int singleNumber(int* nums, int numsSize) {
	unsigned int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	return ret;
}

int main(){
	int a[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
	printf("%d\n", singleNumber(a,9));
	getchar();
	return 0;
}

#endif