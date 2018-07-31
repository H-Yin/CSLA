/*
434. Number of Segments in a String
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A434
#ifdef A434

int countSegments(char* s) {
	int count = 0;
	int i = 0;
	if (s == NULL || s[0] == '\0'){
		return count;
	}
	for (i = 0; s[i+1] != '\0'; i++)
	{
		if (s[i] ==' ' && s[i+1] != ' ')
		{
			count++;
		}
	}
	if (s[0] != ' '){
		count++;
	}
	return count;
}

int main(){
	char a[] = " i am yinhao!";
	printf("%d", countSegments(a));
	return 0;
}

#endif