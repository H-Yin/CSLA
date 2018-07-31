/*
26. Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1, 1, 2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.It doesn't matter what you leave beyond the new length.
*/

#include <stdio.h>

#include "MyArray.h"
/*
int removeDuplicates(int* nums, int numsSize) {
	int pre = 0, cur = 1,watch=0;
	int last = 0, i=0;
	if (numsSize < 2)
	{
		return numsSize;
	}
	watch = -1;
	for (pre = 0, cur = 1; cur < numsSize; cur++){
		if (nums[cur] == nums[pre])
		{
			if (watch == -1)
			{
				watch = cur;
			}
			nums[cur] = nums[0] - 1;
		}else{
			pre = cur;
		}
	}
	if (watch == -1)
	{
		return numsSize;
	}
	// printArray(nums, numsSize);
	// printf("%d\n", watch);
	for (cur = watch; cur < numsSize; cur++){
		if (nums[cur] != nums[0] - 1)
		{
			nums[watch] = nums[cur];
			nums[cur] = nums[0] - 1;
			watch++;
		}
	}
	// printArray(nums, numsSize);
	return watch;
}
*/

int removeDuplicates(int* nums, int numsSize) {
	int pre = 0, cur = 1;
	if (numsSize < 2)
	{
		return numsSize;
	}
	for (pre = 0, cur = 1; cur < numsSize; cur++){
		if (nums[pre] != nums[cur])
		{
			nums[pre + 1] = nums[cur];
			pre++;
		}
	}
	return pre+1;
}

/*int main(){

	int a[] = { 1, 2,2,2,2, 3, 3, 3, 3, 3, 3, 3 };
	printArray(a, 9);
	printf("%d\n",removeDuplicates(a, 9));
	getchar();
	return 0;
}*/
