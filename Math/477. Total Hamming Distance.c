/*
477. Total Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Now your job is to find the total Hamming distance between all pairs of the given numbers.
Example:
Input: 4, 14, 2
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A477
#ifdef A477

int hammingDistance(int x, int y) {
	unsigned int n = x^y, temp;
	temp = n - ((n >> 1) & 0x77777777) - ((n >> 2) & 0x33333333) - ((n >> 3) & 0x11111111);
	return ((temp + (temp >> 4)) & 0x0f0f0f0f) % 255;
}

int totalHammingDistance(int* nums, int numsSize) {
	int i = 0, j = 0, sum=0;
	for (i = 0; i < numsSize-1; i++)
	{
		for (j = i+1; j < numsSize; j++)
		{
			sum += hammingDistance(nums[i], nums[j]);
		}
	}
	return sum;
}

int main(){
	int a[] = { 100, 20, 30, 21, 34, 145 };
	printf("%d", totalHammingDistance(a,2));
	getchar();
	return 0;
}

#endif