/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// #define A14
#ifdef A14

char* longestCommonPrefix(char** strs, int strsSize) {
	char * ret = NULL;
	int i = 1, j = 0, len;
	if (strs == NULL || strsSize < 1)
	{
		return "";
	}
	len = strlen(strs[0]);
	ret = (char*)malloc(sizeof(char)*(len + 1));
	strcpy(ret, strs[0]);
	ret[len] = '\0';
	for (i = 1; i < strsSize; i++){
		j = 0;
		// 跳过公共前缀
		while (ret[j] != '\0' && strs[i][j] != '\0' && ret[j] == strs[i][j])
		{
			j++;
		}
		// 非公共前缀舍去
		if (strs[i][j] == '\0' || ret[j] != strs[i][j]){
			ret[j] = '\0';
		}
		// 无公共前缀，提前退出
		if (ret[0] == '\0')
		{
			return "";
		}
	}
	realloc(ret, strlen(ret)+1);
	return ret;
}

int main(){
	char *a[] = { "c", "c", "c", "c" };
	longestCommonPrefix(a,4);
	getchar();
	return 0;
}

#endif