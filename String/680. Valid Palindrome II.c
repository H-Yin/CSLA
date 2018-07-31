/*
680. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "MyString.h"

// #define A680
#ifdef A680

/*
// ×Ö·û´®Ì«³¤£¬³¬Ê±
bool validPalindrome(char* s) {
	int i = 0, j = 0, k = 0;
	int len = strlen(s), flag = 1;
	j = len - 1;
	for (k=0; k < len; k++)
	{
		flag = 1;
		i = 0, j = len - 1;
		while (i <= j)
		{
			if (i == k){
				i++;
			}
			if (j == k){
				j--;
			}
			if (i<=j && s[i] != s[j]){
				flag = 0;
				break;
			}
			i++;
			j--;
		}
		if (flag){
			return true;
		}
	}
	return false;
}
*/

bool validPalindrome(char* s) {
	int i = 0, j = 0, k = 0;
	int len = strlen(s), flag = 1;
	j = len - 1;
	for (k = 0; k < len; k++)
	{
		flag = 1;
		i = 0, j = len - 1;
		while (i <= j)
		{
			if (i == k){
				i++;
			}
			if (j == k){
				j--;
			}
			if (i <= j && s[i] != s[j]){
				flag = 0;
				break;
			}
			i++;
			j--;
		}
		if (flag){
			return true;
		}
	}
	return false;
}

int main(){
	printf("==:%d\n", validPalindrome(a));
	return 0;
}

#endif