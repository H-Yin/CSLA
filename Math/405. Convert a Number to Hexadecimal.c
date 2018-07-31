/*
405. Convert a Number to Hexadecimal
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two¡¯s complement method is used.

Note:
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A405
#ifdef A405
/*
char* toHex(int num) {
	int i = 7;
	unsigned int x, y;
	char *ret = (char*)malloc(sizeof(char)* 9);
	ret[8] = '\0';
	if (num == 0){
		ret[i] = '0';
		i--;
	}
	else{
		x = (unsigned int)num;
		while (x)
		{
			y = x % 16;
			ret[i] = y >= 10 ? (y - 10 + 'a') : y + '0';
			i--;
			x = x >> 4;
		}
	}
	// bug ÄÚ´æÐ¹Â©
	return ret + i + 1;
}
*/
char* toHex(int num) {
	int i;
	unsigned int x, y, len=0;
	char *ret = NULL;
	if (num == 0){
		return "0";
	}
	if (num < 0)
	{
		len = 8;
	}
	else{
		x = num;
		while (x)
		{
			x = x >> 4;
			len++;
		}
	}
	ret = (char*)malloc(sizeof(char)* (len+1));
	ret[len] = '\0';
	i = len;
	x = (unsigned int)num;
	while (x)
	{
		i--;
		y = x % 16;
		ret[i] = y >= 10 ? (y - 10 + 'a') : y + '0';
		x = x >> 4;
	}
	return ret;
}

int main(){
	for (int i = 0; i < 100; i++){
		printf("%d, %s\n", i, toHex(i));
	}
	getchar();
	return 0;
}

#endif