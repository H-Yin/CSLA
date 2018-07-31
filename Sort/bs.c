#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h> //用到了time函数 


#include<windows.h> 
// (2) 定义使用到的变量

// #define Abs
#ifdef Abs

void PrintArray(int* nums, int numsSize)
{
	printf("[");
	for (int i = 0; i < numsSize; i++){
		printf("%d, ", nums[i]);
	}
	printf("]\n");
}

void randomQuickSort(int *nums, int left, int right){
	int i = left, j = right, number, guard;
	number = rand() % (right - left + 1) + left;
	guard = nums[number];
	nums[number] = nums[i];
	nums[i] = guard;
	while (i<j)
	{
		while (i < j && guard <= nums[j]){
			j--;
		}
		nums[i] = nums[j];
		while (i < j && guard >= nums[i]){
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = guard;
	if (left < i - 1){
		randomQuickSort(nums, left, i - 1);
	}
	if (i + 1 < right){
		randomQuickSort(nums, i + 1, right);
	}
}

void BubbleSort(int *nums, int numsSize){
	int i,j,temp = 0;
	for (i = 0; i < numsSize;i++){
		temp = 0;
		for (j = 0; j < numsSize-1;j++){
			if (nums[j] > nums[j + 1]){
				temp = nums[j+1];
				nums[j+1] = nums[j];
				nums[j] = temp;
			}
		}
	}
}
/*
void ImprovedBubbleSort(int *nums, int numsSize){
	int i, j, temp = 0, flag=1;
	for (i = 0; i < numsSize; i++){
		temp = 0;
		flag = 1;
		for (j = 0; j < numsSize - 1; j++){
			if (nums[j] > nums[j + 1]){
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
				flag = 0;
			}
		}
		if (flag){
			break;
		}
	}
}*/

//void ImprovedBubbleSort(int *nums, int numsSize){
//	int i, j, temp = 0;
//	for (i = 0; i < numsSize; i++){
//		temp = 0;
//		for (j = 0; j < numsSize - i - 1; j++){
//			if (nums[j] > nums[j + 1]){
//				temp = nums[j + 1];
//				nums[j + 1] = nums[j];
//				nums[j] = temp;
//			}
//		}
//	}
//}
void ImprovedBubbleSort(int *nums, int numsSize){
	int i, j, temp = 0, flag = 1;
	for (i = 0; i < numsSize; i++){
		for (flag = 1, j = 0; j < numsSize - i - 1; j++){
			if (nums[j] > nums[j + 1]){
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
				flag = 0;
			}
		}
		if (flag){
			break;
		}
	}
}

int main(){
	int i = 0, j = 0;
	srand((unsigned)time(NULL));

	int *a = NULL;
	int *b = NULL;
	LARGE_INTEGER freq;
	LARGE_INTEGER start_t, stop_t;
	double internel;
	QueryPerformanceFrequency(&freq);
	for (j = 0; j < 10; j++){
		a = (int*)malloc(sizeof(int)* 10000);
		for (i = 0; i < 10000; i++)
		{
			a[i] = rand() % 100001;
		}
		QueryPerformanceCounter(&start_t);
		BubbleSort(a, 10000);
		QueryPerformanceCounter(&stop_t);
		internel = (double)((stop_t.QuadPart - start_t.QuadPart) * 1000.0 / freq.QuadPart);
		printf("Time:%lf\n", internel);
		PrintArray(a, 10);
		free(a);
	}
	printf("\n");
	for (j = 0; j < 10; j++){
		a = (int*)malloc(sizeof(int)* 100000);
		for (i = 0; i < 100000; i++)
		{
			a[i] = rand() % 100001;
		}
		QueryPerformanceCounter(&start_t);
		ImprovedBubbleSort(a, 10000);
		QueryPerformanceCounter(&stop_t);
		internel = (double)((stop_t.QuadPart - start_t.QuadPart) * 1000.0 / freq.QuadPart);
		printf("Time:%lf\n", internel);
		PrintArray(a, 100);
		free(a);
	}
	printf("\n");
	
	for (j = 0; j < 10; j++){
		b = (int*)malloc(sizeof(int)* 100);
		for (i = 0; i < 100; i++)
		{
			b[i] = i;
		}
		for (i = 0; i < 100; i++)
		{
			b[rand() % 100] = rand() % 10001;
		}
		QueryPerformanceCounter(&start_t);
		ImprovedBubbleSort(b, 100);
		QueryPerformanceCounter(&stop_t);
		internel = (double)((stop_t.QuadPart - start_t.QuadPart) * 1000.0 / freq.QuadPart);
		printf("Time:%lf\n", internel);
		PrintArray(b, 100);
		free(b);
	}
	return 0;
}

#endif