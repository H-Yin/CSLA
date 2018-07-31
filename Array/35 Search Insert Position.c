#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	int low = 0, high = numsSize - 1, mid;
	int ret = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (nums[mid] == target){
			return mid;
		}
		else if (nums[mid] > target)
		{
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

//int main(){
//	int nums[4] = { 1 };
//	printf("%d\n", searchInsert(nums, 0, 0));
//	getchar();
//}