#include "MyArray.h"

void printArray(int* nums, int numsSize)
{
	printf("[");
	for (int i = 0; i < numsSize; i++){
		printf("%d, ", nums[i]);
	}
	printf("]\n");
}