/*
441. Arranging Coins
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:
n = 5
The coins can form the following rows:
¤
¤ ¤
¤ ¤
Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8
The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


//#define A441
#ifdef A441

int arrangeCoins(int n) {
	return sqrt(2 * (double)n + 0.25) - 0.5;
}
/*
// 注意溢出问题
int arrangeCoins(int n) {
	return (sqrt(1 + (long)n * 8) - 1) / 2;
}
*/

int main(){
	printf("%d", arrangeCoins(1804289383));
	return 0;
}

#endif