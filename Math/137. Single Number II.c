/*
137. Single Number II
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


//#define A137
#ifdef A137

int singleNumber(int* nums, int numsSize) {
	int i = 0, x = 0,sum=0;
	for (i = 0; i < numsSize; i++){
		x ^= nums[i];
		sum += nums[i];
	}
	printf("%d, %d\n", sum, x);
	x = x&(~(x - 1));
	for (i = 0; i < numsSize; i++){
		// x ^= nums[i];
		sum = sum - nums[i];
		printf("%d, %d, %d, %d\n", nums[i], x^sum^nums[i], sum, sum^nums[i]);
	}
	return x;
}

int main(){
	int a[] = { 3, 10, 5, 25, 2, 8 };
	int len = 0;
	int ret = singleNumber(a, 6);
	printf("%d", ret);
	return 0;
}

#endif