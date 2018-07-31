/*
268. Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
Example 1
Input: [3,0,1]
Output: 2
*/

/*
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A268
#ifdef A268

/*
int missingNumber(int* nums, int numsSize) {
	int i = 0, sum=0;
	while (i <numsSize )
	{
		sum += nums[i];
		i++;
	}
	return (numsSize + 1) * numsSize / 2 - sum;
}
*/

int missingNumber(int* nums, int numsSize) {
	//NOTE 异或操作?     0 ^ a = a， 以及 a ^ b ^ a = b
	int val = numsSize;
	for (int i = 0; i < numsSize; i++) {
		val = val^i^nums[i];
	}
	return val;
}

int main(){
	int a[] = { 0, 1, 3,4,5,6,7 };
	printf("%d", missingNumber(a, 7));
	getchar();
	return 0;
}

#endif