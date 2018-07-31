/*
451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.
Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A451
#ifdef A451

char* frequencySort(char* s) {
	int i = 0, j = 0, k = 0;
	char *ret = NULL;
	int nums[128] = { 0 }, max, clear;
	for (i = 0; s[i] != '\0'; i++){
		nums[s[i]]++;
	}
	ret = (char*)malloc(sizeof(char)*(i+1));
	ret[i] = '\0';

	while (j < i)
	{
		// 找到最大值和下标（对应字符）
		max = nums[0]; clear = 0;
		for ( k = 1; k < 128; k++)
		{
			max = max < nums[k] ? (clear = k),nums[k] : max;
		}
		if (max == 0)
		{
			break;
		}
		nums[clear] = 0; // 最大值清零
		k = max;
		while (k) // 字符串追加
		{
			ret[j] = clear;
			k--;
			j++;
		}
	}
	return ret;
}

int main(){

	printf("==:%s\n", frequencySort("dea"));
	return 0;
}

#endif