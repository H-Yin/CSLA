/*
415. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A204
#ifdef A204
/*
// ¼Ó·¨Ì«¸´ÔÓ
char* addStrings(char* num1, char* num2) {
	int i, j, num, carray = 0, len = 0;
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int maxlen = len2 > len1 ? len2 : len1;
	char *ret = (char*)malloc(sizeof(char)*(maxlen + 1)), *temp;
	memset(ret, '0', sizeof(char)*(maxlen + 1));
	ret[maxlen] = '\0';
	i = 1, j = maxlen-1;
	while (len1-i >=0 && len2-i >= 0)
	{
		num = num1[len1 - i] + num2[len2 - i] - '0' * 2 + carray;
		ret[j] = num % 10 + '0';
		carray = num / 10;
		i++;
		j--;
		len++;
	}
	while (len1 - i >= 0)
	{
		num = num1[len1 - i] - '0' + carray;
		ret[j] = num % 10 + '0';
		carray = num / 10;
		i++;
		j--;
		len++;
	}
	while (len2 - i >= 0)
	{
		num = num2[len2 - i] - '0' + carray;
		ret[j] = num % 10 + '0';
		carray = num / 10 ;
		i++;
		j--;
		len++;
	}
	if (carray != 0){
		len++;
	}
	temp = (char*)malloc(sizeof(char)*(len + 1));
	i = 0;
	if (carray != 0){
		temp[0] = carray + '0';
		i++;
	}
	strcpy(temp + i, ret);
	temp[len] = '\0';
	free(ret);
	return temp;
}
*/

char* addStrings(char* num1, char* num2) {
	int i, j, num, carray = 0, len = 0, n1,n2;
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int maxlen = len2 > len1 ? len2 : len1;
	char *ret = (char*)malloc(sizeof(char)*(maxlen + 2)), *temp;
	memset(ret, '0', sizeof(char)*(maxlen + 1));
	ret[maxlen+1] = '\0';
	i = 1, j = maxlen;
	while (len1 - i >= 0 || len2 - i >= 0)
	{
		n1 = len1 - i >= 0 ? num1[len1 - i] - '0' : 0;
		n2 = len2 - i >= 0 ? num2[len2 - i] - '0' : 0;
		num = n1 + n2 + carray;
		ret[j] = num % 10 + '0';
		carray = num / 10;
		i++;
		j--;
		len++;
	}
	if (carray != 0){
		ret[0] = '1';
	}
	else{
		memmove(ret, ret + 1, len);
		ret[len] = '\0';
	}
	return ret;
}

int main(){
	printf("%s\n", addStrings("99999999999999","1999"));
	return 0;
}

#endif