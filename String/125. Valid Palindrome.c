/*
125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "MyString.h"

// #define A125
#ifdef A125

bool isPalindrome(char* s) {
	int i = 0, j;
	j = strlen(s) - 1;
	while (i <= j)
	{
		while (i <= j && !(IS_LETTER(s[i]) || IS_NUMSER(s[i])))
		{
			i++;
		}
		while (i <= j && !(IS_LETTER(s[j]) || IS_NUMSER(s[j])))
		{
			j--;
		}
		if (i <= j && !(EQUAL_WITHOUT_CASE(s[i], s[j]))){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main(){

	printf("==:%d\n", isPalindrome("0P"));
	return 0;
}

#endif