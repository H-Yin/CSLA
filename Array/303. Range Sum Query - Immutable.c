/*
303. Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A303
#ifdef A303


typedef struct {
	int *nums;
	int *sums;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
	int i = 0;
	NumArray *array = (NumArray *)malloc(sizeof(NumArray));
	if (array != NULL){
		array->nums = (int *)malloc(sizeof(int)*numsSize);
		array->sums = (int *)malloc(sizeof(int)*(numsSize + 1));
		array->sums[0] = 0;
		for (i = 0; i < numsSize; i++)
		{
			array->nums[i] = nums[i];
			array->sums[i + 1] = array->sums[i] + nums[i];
		}
	}
	return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
	return (obj->sums[j+1] - obj->sums[i]);
}

void numArrayFree(NumArray* obj) {
	free(obj->nums);
	free(obj->sums);
	free(obj);
}

/**
* Your NumArray struct will be instantiated and called as such:
* 
*/

int main(){
	int a[] = { -2, 0, 3, -5, 2, -1 };
	struct NumArray* obj = numArrayCreate(a, 6);
	int param_1 = numArraySumRange(obj, 3, 5);
	printf("%d\n", param_1);
	numArrayFree(obj);

	return 0;
}

#endif