/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A28
#ifdef A28

/*
int strStr(char* haystack, char* needle) {
	int i, j,k, ret = -1;
	char *p = haystack, *s = needle;
	if (haystack == NULL || needle == NULL || (haystack[0] == '\0' && needle[0] != '\0'))	{
		return -1;
	}
	if (needle[0] == '\0'){
		return 0;
	}

	for (i = 0; p[i] != '\0'; i++){
		j = 0;
		k = i;
		while (s[j] != '\0' && p[k]==s[j])
		{
			k++;
			j++;
		}
		if (s[j] == '\0')
		{
			return i;
		}
	}
	return -1;
}
*/

int strStr(char* haystack, char* needle) {
	int aLen = strlen(haystack), bLen = strlen(needle);
	if ((aLen == 0 || bLen == 0) && aLen >= bLen)
		return 0;
	if (aLen < bLen)
		return -1;
	int matchSize = 0;
	// 在父串中搜索的长度为 aLen - bLen
	for (int i = 0; i < aLen - bLen + 1; ++i) {
		matchSize = 0;
		if (haystack[i] == needle[0]){
			matchSize++;
			for (int j = 1; j < bLen; ++j){
				if (haystack[i + j] == needle[j]){
					matchSize++;
				}
			}
			if (matchSize == bLen)
				return i;
		}
	}
	return -1;
}

int main(){
	printf("%d", strStr("cbcadbde", "abc"));
	getchar();
	return 0;
}

#endif