#include <stdio.h>
#include <stdlib.h>

// #define A728
#ifdef A728
#include "MyArray.h"
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* selfDividingNumbers(int left, int right, int* returnSize) {
	int i = 0, j=0, x;

	int *ret = (int*)malloc(sizeof(int)*(right - left + 1));
	if (ret == NULL){
		return NULL;
	}
	*returnSize = 0;
	for (i = left; i <= right; i++)
	{
		x = i;
		// 判断每个数字是否是self dividing
		while (x)
		{
			// 不含数字 0，且能 self dividing
			if ((x % 10) != 0 && i % (x % 10) == 0)
			{
				x = x / 10;
			}
			else{
				break;
			}
		}
		// 如果是的话，存到 ret 中
		if (x == 0)
		{
			ret[j] = i;
			(*returnSize)++;
			j++;
		}
	}
	return ret;
}

int main(){
	int len = 0;
	int *ret = selfDividingNumbers(1, 22, &len);
	printArray(ret, len);
	getchar();
}
#endif