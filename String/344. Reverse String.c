/*
344. Reverse String
Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>


// #define A344
#ifdef A344
/*
char* reverseString(char* s) {
	int i = 0, j = strlen(s);
	char *ret = NULL;
	if (s == NULL){
		return NULL;
	}
	ret = (char*)malloc(sizeof(char)*(j + 1));
	while (i < j)
	{
		ret[i] = s[j-i-1];
		i++;
	}
	ret[j] = '\0';
	return ret;
}*/
char* reverseString(char* s) {
	int i = 0, j = strlen(s)-1;
	char temp;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return s;
}

int main(){
	char a[] = "abcdef";
	printf("%s", reverseString(a));
	getchar();
	return 0;
}

#endif