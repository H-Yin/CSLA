/*
717. 1-bit and 2-bit Characters
bits (10 or 11).
Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.
Example 1:
Input:
bits = [1, 0, 0]
Output: True
Explanation:
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input:
bits = [1, 1, 1, 0]
Output: False
Explanation:
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A717
#ifdef A717
/*

bool isOneBitCharacter(int* bits, int bitsSize) {
	int i = 0;
	for (i = 0; i < bitsSize-1;)
	{
		if (bits[i] == 1){
			i += 2;
		}
		else{
			i++;
		}
	}
	if (i == bitsSize - 1){
		return true;
	}
	return false;
}
*/
bool isOneBitCharacter(int* bits, int bitsSize) {
	int i = 0;
	for (i = 0; i < bitsSize - 1;i++)
	{
		if (bits[i] == 1){
			i++;
		}
	}
	if (i == bitsSize - 1){
		return true;
	}
	return false;
}

int main(){
	int bits[] = { 0, 0, 1, 0, 0};
	printf("\n%d", isOneBitCharacter(bits, 4));
	return 0;
}

#endif