/*
520. Detect Capital
Given a word, you need to judge whether the usage of capitals in it is right or not.
We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A520
#ifdef A520

bool detectCapitalUse(char* word) {
	char *p = word;
	int len = 0, a = 0, b = 0;
	while (*p)
	{
		if (*p >= 'A' && *p <='Z')
		{
			a++;
		}
		else{
			b++;
		}
		len++;
		p++;
	}
	if ((word[0] >= 'A' && word[0]<= 'Z' && a==1 )|| a == len || b == len)
	{
		return true;
	}
	return false;
}

int main(){
	printf("%d", detectCapitalUse("USA"));
	return 0;
}

#endif