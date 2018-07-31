/*
10. Regular Expression Matching
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true
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