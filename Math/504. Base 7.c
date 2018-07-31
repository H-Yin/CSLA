/*
504. Base 7
Given an integer, return its base 7 string representation.
Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A504
#ifdef A504

char* convertToBase7(int num) {
	int x = num >= 0 ? num : -num,
		len = 0,
		flag = num >= 0 ? 0 : 1;
	char *ret = NULL;
	// 0 做特殊处理
	if (x == 0)
	{
		return "0";
	}
	// 或去长度
	while (x)
	{
		x = x / 7;
		len++;
	}
	x = num >= 0 ? num : -num;
	if (flag){
		len++;
	}
	// 转换进制
	ret = (char*)malloc(sizeof(char)*(len + 1));
	ret[len] = '\0';
	while (x)
	{
		len--;
		ret[len] = x % 7 + '0';
		x = x / 7;
	}
	if (flag){
		ret[0]='-';
	}
	return ret;
}

int main(){
	printf("%s",convertToBase7(0));
	return 0;
}

#endif