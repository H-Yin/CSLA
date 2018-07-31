/*
189. Rotate Array
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A189
#ifdef A189

#include "MyArray.h"
// 空间复杂度为O(k)
//void rotate(int* nums, int numsSize, int k) {
//	int i = 0,j=0;
//	int *temp = NULL;
//	k = k % numsSize; // 循环右移
//	temp = (int*)malloc(sizeof(int)*(k));
//	if (k <= 0 || numsSize <= 0){
//		return;
//	}
//	for (i = numsSize - k, j = 0; i < numsSize; i++,j++)
//	{
//		temp[j] = nums[i];
//	}
//	for (i = numsSize - k-1; i >=0; i--)
//	{
//		nums[i + k] = nums[i];
//	}
//	for (i = 0; i < k; i++)
//	{
//		nums[i] = temp[i];
//	}
//	free(temp);
//}

void rotate(int* nums, int numsSize, int k) {
	int i = 0,j=0;
	int *temp = NULL;
	temp = (int*)malloc(sizeof(int)*(k));
	if (k <= 0 || numsSize <= 0){
		return;
	}
	for (i = numsSize - k, j = 0; i < numsSize; i++,j++)
	{
		temp[j] = nums[i];
	}
	for (i = numsSize - k-1; i >=0; i--)
	{
		nums[i + k] = nums[i];
	}
	for (i = 0; i < k; i++)
	{
		nums[i] = temp[i];
	}
	free(temp);
}

int main(){
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	rotate(a, 7, 0);
	printArray(a, 7);
	return 0;
}

#endif