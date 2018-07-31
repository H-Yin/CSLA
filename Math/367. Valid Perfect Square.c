/*
367. Valid Perfect Square
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.
Example 1:
Input: 16
Returns: True
Example 2:
Input: 14
Returns: False
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A367
#ifdef A367

bool isPerfectSquare(int num) {
	int left = 0, right = num;
	long middle=0L, x=0L;
	while (left <= right)
	{
		middle = (long)(left + right) / 2;
		x = middle * middle - num;
		if (x == 0){
			return true;
		}
		else if (x > 0){
			right = middle - 1;
		}
		else{
			left = middle + 1;
		}
	}
	return false;
}

int main(){
	printf("%d", isPerfectSquare(2147483647));
	return 0;
}

#endif