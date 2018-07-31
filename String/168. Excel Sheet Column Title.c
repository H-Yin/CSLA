/*
168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A168
#ifdef A168

char* convertToTitle(int n) {
	char *ret = NULL;
	int x = n, i =6;
	ret = (char*)malloc(sizeof(char)* 8);
	ret[7] = '\0';
	while (x)
	{
		ret[i] = (x-1) % 26 + 'A';
		x = (x-1)/ 26;
		i--;
	}
	return ret+i+1;
}

int main(){
	for (int i = 1; i < 100; i++){
		printf("%d, %s\n", i, convertToTitle(i));
	}
	return 0;
}

#endif