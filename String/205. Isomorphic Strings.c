/*
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A205
#ifdef A205

bool isIsomorphic(char* s, char* t) {
	int len = strlen(s), flag[128] = { 0 }, count = 0, i=0;
	char *sTemp, *tTemp, *p, *q;
	bool ret = false;
	sTemp = (char*)malloc(sizeof(char)*(len + 1));
	tTemp = (char*)malloc(sizeof(char)*(len + 1));
	tTemp[len] = sTemp[len] = '\0';
	for (p = s, i = 0, count = 0; *p; p++, i++)
	{
		if (flag[*p] == 0)
		{
			flag[*p] = count + 'a';
			count++;
		}
		sTemp[i] = flag[*p];
	}
	memset(flag, 0, sizeof(flag));
	for (q = t, i = 0, count = 0; *q; q++, i++)
	{
		if (flag[*q] == 0)
		{
			flag[*q] = count + 'a';
			count++;
		}
		tTemp[i] = flag[*q];
	}
	ret = (strcmp(sTemp, tTemp) == 0);
	free(sTemp);
	free(tTemp);
	return ret;
}

int main(){
	printf("%d", isIsomorphic("eff", "add"));

	return 0;
}

#endif