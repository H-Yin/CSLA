/*

27. Remove Element

Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/


#include <stdio.h>
#include "MyArray.h"

int removeElement(int* nums, int numsSize, int val) {
	int low = 0, high = numsSize - 1, len = numsSize;
	while (low <= high)
	{
		if (nums[low] == val){
			while (low < high && nums[high] == val)
			{
				high--;
				len--;
			}
			nums[low] = nums[high];
			len--;
			high--;
		}
		low++;
	}
	return len;
}
//int main(){
//
//	//int a[] = { 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3 };
//	int a[] = { 0, 4, 4, 0, 4, 4, 4, 0, 2};
//	printArray(a, 9);
//	printf("%d\n", removeElement(a, 9,4));
//	getchar();
//	return 0;
//}
