/*

41. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


#include <stdio.h>
#include <math.h>
#include "MyArray.h"
//int firstMissingPositive(int* nums, int numsSize) {
//	int first = 1;
//	int sum_n = 0; // ǰn�������ĺ�
//	int sum_max = 0; // ǰ max�������ĺ�
//	int sum_count = 0; // ǰ count �������ĺ�
//	int max_n = 0; // ǰn �����е����ֵ
//	int count_n = 0;
//	int i = 0;
//	int temp_sum = 0, temp_squ = 0;
//	int flag = 1;
//	if (nums == NULL || numsSize == 0)
//	{
//		return first;
//	}
//	for (i = 0; i < numsSize; i++){
//		if (nums[i] < 1)
//		{
//			continue;
//		}
//		count_n++;
//		if (max_n < nums[i]){
//			max_n = nums[i];
//		}
//		sum_n += nums[i];
//		sum_max = max_n * (max_n + 1) / 2;
//		sum_count = (count_n + 1)*(count_n + 2) / 2; 
//		if (sum_count >= sum_max)
//		{
//			if (sum_max - sum_n == 0){
//				first = max_n + 1;
//			}
//			else if (true)
//			{
//
//			}
//			
//
//		}
//	}
//	return first;
//}
//int main(){
//
//	//int a[] = { 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3 };
//	int a[] = { 1, 4, -1, 2, 6, 4, 4, 0, 2 };
//	printArray(a, 5);
//	printf("%d\n", firstMissingPositive(a, 5));
//	getchar();
//	return 0;
//}
