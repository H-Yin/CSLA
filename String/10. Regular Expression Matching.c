/*
10. Regular Expression Matching
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A10
#ifdef A10

bool isMatch(char* s, char* p) {
	int i=0, j=0, flag;
	while (s[i] && p[j])
	{
		if (p[j] == '*'){
			flag = true;
		}
		if (s[i] != p[j] && (p[j] != '.' || p[j] != '*')){
			break;
		}
		if (p[j] == '*'){
			j++;
		}
		
		if (s[i] == p[i] || p[i] == '.'){
			i++;
		}
		else{

		}
	}
}


int main(){
	return 0;
}

#endif