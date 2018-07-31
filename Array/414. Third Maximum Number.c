/*
414. Third Maximum Number
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A414
#ifdef A414

int thirdMax(int* nums, int numsSize) {
	int max1 = -2147483648, max2 = -2147483648, max3 = -2147483648, i = 0, count = 0, flag=0;
	for (i = 0; i < numsSize; i++){
		if (nums[i] > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
			count++;
		}
		else if (nums[i] > max2 && nums[i] < max1)
		{
			max3 = max2;
			max2 = nums[i];
			count++;
		}
		else if (nums[i] > max3 && nums[i] < max2){
			max3 = nums[i];
			count++;
		}
		else if(flag == 1 && nums[i] == max3 && max3 == -2147483648)
		{
			max3 = nums[i];
			count++;
			flag = 0;
		}	
	}
	if (count < 3)
	{
		return max1;
	}
	return max3;
}

int main(){
	int a[] = {-2147483648, -2147483648, -2147483648, -2147483648, 1, 1, 1};
	printf("%d", thirdMax(a,5));
	return 0;
}

#endif