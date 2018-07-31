/*
485. Max Consecutive Ones
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A485
#ifdef A485

int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int i, k, max = 0;
	for (i = 0; i < numsSize; i++)
	{
		k = 0;
		while (i < numsSize && nums[i] == 1)
		{
			i++;
			k++;
		}
		if (k> max){
			max = k;
		}
	}
	return max;
}

int main(){
	int a[] = { 0, 1,};
	printf("%d", findMaxConsecutiveOnes(a,6));
	getchar();
	return 0;
}

#endif