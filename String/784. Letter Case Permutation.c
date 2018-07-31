/*
784. Letter Case Permutation
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A784
#ifdef A784

#include "MyString.h"

char** letterCasePermutation(char* S, int* returnSize) {
	
	int i = 0, j = 0, k=0, flag=0;
	int num = 0, len = 0;
	char *p = S;
	char **ret = NULL;
	// 计算字符串长度和字母个数
	for (p = S; *p != '\0'; p++){
		if (!(*p >= '0' && *p <= '9'))
			num++;
		len++;
	}
	// 计算生成的字符串个数
	*returnSize = (1 << num);
	// 生成字符串数组
	ret = (char**)malloc(sizeof(char*)*(*returnSize));
	for (i = 0; i < *returnSize; i++)
	{
		ret[i] = (char*)malloc(sizeof(char)*(len+1));
		ret[i][len] = '\0';
	}
	// printf("%d,%d\n", len, *returnSize);
	// 每个字符按组合生成
	for (i = 0; S[i] != '\0'; i++)
	{
		flag = 0;
		for (j = 0; j < *returnSize; j++)
		{
			if (S[i] >= '0' && S[i] <= '9')
			{
				ret[j][i] = S[i];
			}
			else{
				if (j%(1<<k) == 0)
				{
					flag++;
				}
				if (flag % 2){
					ret[j][i] = toLowerCase(S[i]);
				}
				else{
					ret[j][i] = toUpperCase(S[i]);
				}
			}
		}
		if (!(S[i] >= '0' && S[i] <= '9'))
		{
			k++;
		}
	}
	return ret;
}

int main(){
	char s[] = "a1b2c3d4e5f6g7h8i9k1l2";
	int len = 0, i;
	char** ret = letterCasePermutation(s, &len);
	for (i = 0; i < len; i++)
	{
		printf("%s\n", ret[i]);
	}
	return 0;
}

#endif