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

// #define A169
#ifdef A169

int majorityElement(int* nums, int numsSize) {
	int i=0, j = numsSize-1;
	while (i<j)
	{
		if (nums[i] != nums[j]){
			j--;
		}
		i++;
	}
	return nums[i];
}

int main(){
	int a[] = { 3,2,3 };
	printf("%d", majorityElement(a, 3));
	getchar();
	return 0;
}

#endif