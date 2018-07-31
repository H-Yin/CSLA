/*
461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ¡Ü x, y < 231.
Example:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
      ¡ü   ¡ü
The above arrows point to positions where the corresponding bits are different.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

//#define A461
#ifdef A461

int hammingDistance(int x, int y) {
	unsigned int n=x^y, temp;
	temp = n - ((n >> 1) & 0x77777777) - ((n >> 2) & 0x33333333) - ((n >> 3) & 0x11111111);
	return ((temp + (temp>>4)) & 0x0f0f0f0f) % 255;
	//return bit_count(x^y);
}

int main(){
	printf("%d", hammingDistance(1577962638, 1727613287));
	getchar();
	return 0;
}

#endif