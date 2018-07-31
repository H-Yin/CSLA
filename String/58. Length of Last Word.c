/*
58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
Example:
Input: "Hello World"
Output: 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A58
#ifdef A58

int lengthOfLastWord(char* s) {
	int len = 0, i ,flag = 0;
	for (i = 0; s[i] !='\0'; )
	{
		flag = 0;
		while (s[i] != '\0' && s[i] == ' ')
		{
			i++;
			flag = 1;
		}
		if (flag){
			continue;
		}
		len = 0;
		while (s[i]!= '\0' && s[i] != ' ')
		{
			len++;
			i++;
		}
	}
	return len;
}

int main(){
	printf("%d\n", lengthOfLastWord(" a "));
	return 0;
}

#endif
