/*
796. Rotate String
We are given two strings, A and B.
A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.
Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A796
#ifdef A796

bool rotateString(char* A, char* B) {
	int lenA = 0, lenB = 0;
	int i, j, flag;
	char *p = A, *q = B;
	while (*p)
	{
		lenA++;
		p++;
	}
	while (*q)
	{
		lenB++;
		q++;
	}
	if (lenA != lenB){
		return false;
	}
	for (i = 0; i < lenA; i++){
		flag = true;
		for (j= 0; j < lenB; j++)
		{
			if (A[(i + j) % lenA] != B[j]){
				flag = false;
				break;
			}
		}
		if (flag){
			break;
		}
	}
	return flag;
}

int main(){
	printf("%d", rotateString("abcde", "bcdea"));
	getchar();
	return 0;
}

#endif