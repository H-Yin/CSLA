/*
66. Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "MyArray.h";

// #define A66
#ifdef A66

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int *ret;
	int i = digitsSize - 1, j = 0, carray = 0, temp;
	carray = (digits[i] + 1) / 10;
	digits[i] = (digits[i] + 1) % 10;
	for (i = digitsSize-2; i >=0 ; i--)
	{
		temp = digits[i] + carray;
		digits[i] = temp % 10;
		carray = temp / 10;
		if (carray == 0 )
		{
			break;
		}
	}
	*returnSize = digitsSize;
	if (carray !=0 )
	{
		*returnSize += 1;
	}
	ret = (int*)malloc(sizeof(int)*(*returnSize));
	if (carray != 0)
	{
		ret[0] = 1;
		j++;
	}
	for (i = 0; i < digitsSize; i++,j++)
	{
		ret[j] = digits[i];
	}
	return ret;
}

int main(){
	int a[] = {0};
	int len = 0;
	int * res = plusOne(a, 1, &len);
	printArray(res, len);
	return 0;
}

#endif