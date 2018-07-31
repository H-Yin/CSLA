/*
561. Array Partition I
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h> //用到了time函数 

// #define A561
#ifdef A561

#include "MyArray.h"


void randomQuickSort(int *nums, int left, int right){
	int i = left, j = right, number, guard ;
	number = rand() % (right -left+1) +left;
	printf("letf:%d\tRight:%d\tRandom:%d\t", left, right, number);
	printArray(nums, 10);	
	guard = nums[number];
	nums[number] = nums[i];
	nums[i] = guard;
	while (i<j)
	{
		while (i < j && guard <= nums[j]){
			j--;
		}
		nums[i] = nums[j];
		while (i < j && guard >= nums[i]){
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = guard;
	printf("\t");
	printArray(nums, 10);
	if (left < i - 1){
		randomQuickSort(nums, left, i - 1);
	}
	if (i+1 < right){
		randomQuickSort(nums, i+1, right);
	}
}

void quickSort(int *nums, int left, int right){
	int i = left, j = right, guard = nums[i];
	while (i<j)
	{
		while (i < j && guard <= nums[j]){
			j--;
		}
		nums[i] = nums[j];
		while (i < j && guard >= nums[i]){
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = guard;
	if (left < i - 1){
		quickSort(nums, left, i - 1);
	}
	if (i+1 < right){
		quickSort(nums, i+1, right);
	}
}

int arrayPairSum(int* nums, int numsSize) {
	int i = 0, sum = 0;
	randomQuickSort(nums, 0, numsSize - 1);
	for (i = 0; i < numsSize; i+=2){
		sum += nums[i];
	}
	return sum;
}

int main(){
	srand((unsigned) time(NULL)); 
	int a[] = { 1,2,4,3,5,6,7,8,9,10 };
	// quickSort(a, 0, 9);
	printArray(a, 10);
	printf("%d", arrayPairSum(a, 10));

	return 0;
}

#endif