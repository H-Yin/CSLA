/*
307. Range Sum Query - Mutable
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A307
#ifdef A307


typedef struct {
	int *nums;
	int *sums;
	int numsSize;
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
		array->numsSize = numsSize;
	}
	return array;
}

void numArrayUpdate(NumArray* obj, int i, int val) {
	if (obj->numsSize <= i){
		return;
	}
	int diff = val - obj->nums[i] , j=i;
	obj->nums[i] = val;
	for (j; j < obj->numsSize; j++)
	{
		obj->sums[j + 1] = obj->sums[j + 1] + diff;
	}
}

int numArraySumRange(NumArray* obj, int i, int j) {
	return (obj->sums[j + 1] - obj->sums[i]);
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
	int a[] = { 1,3,5 };
	struct NumArray* obj = numArrayCreate(a, 3);
	int param_1 = numArraySumRange(obj, 0, 2);
	printf("%d\n", param_1);
	numArrayUpdate(obj, 1, 2);
	param_1 = numArraySumRange(obj, 0, 2);
	printf("%d\n", param_1);
	numArrayFree(obj);

	return 0;
}

#endif