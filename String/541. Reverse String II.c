/*
541. Reverse String II
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define A541
#ifdef A541

char* reverseStr(char* s, int k) {
	int len = strlen(s);
	char temp;
	int i, j, m;
	for (i = 0; i < len; i += 2 * k)
	{
		m = i + k - 1;
		if (m >= len){
			m = len - 1;
		}
		for (j = i;j<m; j++,m--){
			temp = s[j];
			s[j] = s[m];
			s[m] = temp;
		}
	}
	return s;
}

int main(){
	char a[] = "abcdefg";
	printf("%s", reverseStr(a, 8));
	getchar();
	return 0;
}

#endif