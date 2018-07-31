/*
409. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"
Output:
7
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A409
#ifdef A409

int longestPalindrome(char* s) {
	int nums[52] = { 0 }, ret = 0, len = 0;
	int i = 0;
	for (  i=0;  s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			nums[s[i] - 'A' + 26]++;
		}
		else{
			nums[s[i] - 'a']++;
		}
		len++;
	}
	for ( i = 0; i < 52; i++)
	{
		if (nums[i] % 2 == 1){
			ret += nums[i]-1;
		}
		else{
			ret += nums[i];
		}
	}
	if (ret < len)
	{
		ret++;
	}
	return ret;
}

int main(){
	
	printf("==:%d\n",longestPalindrome("abcckiuqwdhASDjgadhGSHAGSHSDGyqwywtyqtweyqteyqtwejasbbsdhaSHDQWYccdd"));
	return 0;
}

#endif

