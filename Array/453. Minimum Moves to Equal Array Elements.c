/*
453. Minimum Moves to Equal Array Elements
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
Example:
Input:
[1,2,3]
Output:
3
Explanation:
Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "MyArray.h"

// #define A453
#ifdef A453
/*
// 超时
int minMoves(int* nums, int numsSize) {
	int flag = 0, min, max, num = 0;
	int i = 0, ret=0;
	int *temp = (int *)malloc(sizeof(int)*numsSize);
	for (i = 0; i < numsSize; i++)
	{
		temp[i] = nums[i];
	}
	while (1){
		min = max = temp[0];
		// 找到最大值
		for (i = 1; i < numsSize; i++){
			max = max < temp[i] ? temp[i] : max;
			min = min > temp[i] ? temp[i] : min;
		}
		num = max - min;
		if (num == 0){
			break;
		}
		ret += num;
		for (flag = 1, i = 0; i < numsSize; i++){
			if (temp[i] == max){
				if (flag == 1){
					flag = 0;
					continue;
				}
			}
			temp[i] += num;
		}
	}
	free(temp);
	return ret;
}
*/

int minMoves(int* nums, int numsSize) {
	int i = 0, min, sum = 0;
	sum = min = nums[0];
	// 找到最大值
	for (i = 1; i < numsSize; i++){
		min = min > nums[i] ? nums[i] : min;
		sum += nums[i];
	}
	return sum - numsSize * min;
}

int main(){
	int a[] = {6,3, 9 };
	printf("%d\n", minMoves(a, 3));
	return 0;
}

#endif
