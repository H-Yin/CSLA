/*
448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[5,6]
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "MyArray.h"

// #define A448
#ifdef A448


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int i = 0, temp;
	for (i = 0; i < numsSize; i++) {
		int m = abs(nums[i]) - 1; // index start from 0
		nums[m] = nums[m]>0 ? -nums[m] : nums[m];
	}

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > 0 )
		{
			nums[nums[i]-1] = -1;
			printArray(nums, numsSize);
		}
	}
	return NULL;
}

int main(){
	int a[] = { 5, 4, 3, 2, 5, 7, 8, 1, 9, 1 };
	int len;
	findDisappearedNumbers(a, 10, &len);

	return 0;
}

#endif