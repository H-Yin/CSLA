/*
557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>


// #define A557
#ifdef A557

char* reverseWords(char* s) {
	int i = 0, j = 0, k = 0, temp, len = strlen(s);
	char *ret = (char*)malloc(sizeof(char)*(len + 1));
	strcpy(ret, s);
	ret[len] = '\0';
	for (i = 0,j=i; i <= len; i++)
	{
		if (ret[i] == ' ' || ret[i] == '\0'){
			k = i-1;
			while (j<k)
			{
				temp = ret[j];
				ret[j] = ret[k];
				ret[k] = temp;
				j++;
				k--;
			}
			i++;
			j = i;
		}
	}
	return ret;
}

int main(){
	char a[] = "Let's take LeetCode contest";
	printf("%s", reverseWords(a));
	getchar();
	return 0;
}

#endif