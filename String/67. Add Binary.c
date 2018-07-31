/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A67
#ifdef A67

char* addBinary(char* a, char* b) {
	int len1 = strlen(a);
	int len2 = strlen(b);
	int maxlen = len1 > len2 ? len1 : len2;

	int carray = 0, i = len1 - 1, j = len2 - 1, k, n1, n2;
	char * ret = (char*)malloc(sizeof(char)*(maxlen + 2));
	ret[maxlen + 1] = '\0';
	k = maxlen;
	while (i >= 0 || j>=0)
	{
		n1 = i >= 0 ? a[i--] - '0' : 0;
		n2 = j >= 0 ? b[j--] - '0' : 0;
		ret[k--] = (n1 + n2 + carray) % 2 + '0';
		carray = (n1 + n2 + carray) / 2;
	}
	if (carray != 0)
	{
		ret[0] = '1';
	}
	else{
		memmove(ret, ret + 1, maxlen + 1);
	}
	return ret;
}

int main(){
	printf("%s\n", addBinary("1", "111"));
	return 0;
}

#endif