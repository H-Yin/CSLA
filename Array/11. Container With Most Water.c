/*
11. Container With Most Water
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A11
#ifdef A11

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int maxArea(int* height, int heightSize) {
	int i = 0, j =heightSize-1;
	int ret = 0;
	while (i<j)
	{
		// 判断是否是最大的
		ret = MAX(ret, MIN(height[i], height[j])*(j - i));
		// 继续搜索比小边界大的边界
		if (height[i] < height[j])
		{
			i++;
		}
		else{
			j--;
		}
	}
	return ret;
}

int main(){
	int a[] = { 1, 1 };
	printf("%d", maxArea(a, 2));
	return 0;
}

#endif

