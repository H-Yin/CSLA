/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


#define A11
#ifdef A11

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int trap(int* height, int heightSize) {
	int i =0, j =1, k = 2;
	int sub = 0, sum = 0, min;
	if (k + 1 > heightSize){
		return 0;
	}
	while (k < heightSize)
	{
		
		if (height[i] > height[j] && height[j] < height[k]){
			sub = height[j];
			while (i>0 && height[i - 1] > height[i]){
				sub += height[i];
				i--;
			}
			while (k+1<heightSize && height[k] < height[k+1]){
				sub += height[k];
				k++;
			}
			min = MIN(height[i], height[k]);
			sum += (k - i-1) * min -sub;
			while (i+1<k)
			{
				if (height[i + 1] > height[k]){
					sum += height[i + 1] - min;
				}
				i++;
			}
			// printf("%d, %d, %d, %d\n", height[i], height[k], k-i-1, sum);
			i = k - 1;
			j = k ;
			k = k + 1;
		}
		i = i + 1;
		j = j + 1;
		k = k + 1;
	}
	return sum;
}

int main(){
	int a[] = {6, 5,4,1,2 };
	printf("%d", trap(a, 5));
	return 0;
}

#endif
