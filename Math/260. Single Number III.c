/*
260. Single Number III
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A260
#ifdef A260


int* singleNumber(int* nums, int numsSize, int* returnSize) {
	int i = 0, xor = 0;
	int *ret = NULL;
	for (i = 0; i < numsSize;i++){
		xor ^= nums[i];
	}
	if (xor == 0){
		*returnSize = 0;
		return NULL;
	}
	*returnSize = 2;
	ret = (int*)malloc(sizeof(int)* 2);
	ret[0] = ret[1] = 0;
	int bitflag = (xor & (~(xor - 1)));
	for (i = 0; i < numsSize; i++){
		if ((bitflag & nums[i]) == 0){
			ret[0] ^= nums[i];
		}
		else{
			ret[1] ^= nums[i];
		}
	}
	return ret;
}

int main(){
	int a[] = { 1, 2, 1, 2, 3, 5 };
	int len = 0;
	int *ret = singleNumber(a, 6, &len);
	printf("%d,%d", ret[0], ret[1]);
	return 0;
}

#endif

