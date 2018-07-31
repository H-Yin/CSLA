#include <stdio.h>
//
//int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
//	int low = 0, high = numsSize - 1, mid;
//	int ret = -1;
//	double x = target + 0.5;
//	int *retArr = (int *)malloc(sizeof(int) * 2);
//	*returnSize = 2;
//	if (retArr == NULL){
//		return NULL;
//	}
//
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (nums[mid] == target){
//			ret = mid;
//			break;
//		}
//		else if (nums[mid] > target)
//		{
//			high = mid - 1;
//		}
//		else{
//			low = mid + 1;
//		}
//	}
//	if (ret == -1)
//	{
//		*(retArr + 0) = -1;
//		*(retArr + 1) = -1;
//		return retArr;
//	}
//	low = 0;
//	high = ret - 1;
//	x = target - 0.5;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (nums[mid] > x)
//		{
//			high = mid - 1;
//		}
//		else if (nums[mid] < x){
//			low = mid + 1;
//		}
//	}
//	*(retArr + 0) = low;
//
//	low = ret + 1;
//	high = numsSize - 1;
//	x = target + 0.5;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (nums[mid] > x)
//		{
//			high = mid - 1;
//		}
//		else if (nums[mid] < x){
//			low = mid + 1;
//		}
//	}
//	*(retArr + 1) = high;
//	return retArr;
//}


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	int low = 0, high = numsSize - 1, mid;
	int ret = -1;
	double x = target + 0.5;
	int *retArr = (int *)malloc(sizeof(int)* 2);
	*returnSize = 2;
	if (retArr == NULL){
		return NULL;
	}
	// 找 starting
	x = target - 0.5;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (nums[mid] > x)
		{
			high = mid - 1;
		}
		else if (nums[mid] < x){
			low = mid + 1;
		}
	}
	*(retArr + 0) = low;

	low = 0;
	high = numsSize - 1;
	// 找 ending
	x = target + 0.5;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (nums[mid] > x)
		{
			high = mid - 1;
		}
		else if (nums[mid] < x){
			low = mid + 1;
		}
	}
	*(retArr + 1) = high;
	// 判断是否找到，low_ending > low_staring 则表示找到，low_ending <= low_staring 则表示没有找到。
	if (*(retArr + 0) == low){
		*(retArr + 0) = *(retArr + 1) = -1;
	}
	return retArr;
}

//int main(){
//	int nums[6] = { 5, 7, 7, 8, 8, 10};
//	int rets;
//	int *a = searchRange(nums, 6, 1, &rets);
//	printf("%d %d\n", *(a+0),*(a+1));
//	getchar();
//}