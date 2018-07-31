/*
345. Reverse Vowels of a String
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
Note:
The vowels does not include the letter "y".
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A345
#ifdef A345

// ÅÐ¶Ï×Ö·ûÊÇ·ñÊÇÔªÒô×ÖÄ¸
bool isVowels(char ch){
	if (ch == 'a' || ch == 'A'
		|| ch == 'e' || ch == 'E'
		|| ch == 'i' || ch == 'I'
		|| ch == 'o' || ch == 'O'
		|| ch == 'u' || ch == 'U'){
		return true;
	}
	return false;
}

char* reverseVowels(char* s) {
	int i, j, len;
	char *ret = NULL, temp;
	len = strlen(s);
	// ¿½±´×Ö·û´®
	ret = malloc(sizeof(char)*(len + 1));
	for (i = 0; i < len; i++)
	{
		ret[i] = s[i];
	}
	ret[len] = '\0';

	i = 0; j = len - 1;
	while (i < j)
	{
		// ´ÓÁ½¶Ë²éÕÒÔªÒô×ÖÄ¸
		while (i < j && !isVowels(ret[j])){
			j--;
		}
		while (i < j && !isVowels(ret[i])){
			i++;
		}
		// ½»»»Á½¸öÔªÒô×ÖÄ¸
		if (i < j){
			temp = ret[i];
			ret[i] = ret[j];
			ret[j] = temp;
			i++;
			j--;
		}
	}
	return ret;
}

int main(){
	char a[] = "hElioulo";
	printf("%s", reverseVowels(a));
	return 0;
}

#endif