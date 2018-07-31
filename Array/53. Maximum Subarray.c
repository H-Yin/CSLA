/*
53. Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A53
#ifdef A53
int maxSubArray(int* nums, int numsSize) {
	int sum = 0;
	int i, max = 0, ret;
	if (nums == NULL || numsSize < 1){
		return 0;
	}
	if (numsSize == 1){
		return nums[0];
	}
	max = nums[0];
	for (i = 1; i < numsSize; i++)
	{
		sum += nums[i];
		max = max < sum ? sum : max;
		sum = sum > 0 ? sum : 0;
	}
	return max;
}
int main(){
	int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	printf("%d", maxSubArray(a,9));
	return 0;
}

#endif