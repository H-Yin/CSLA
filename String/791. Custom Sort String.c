/*
791. Custom Sort String
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.
Return any permutation of T (as a string) that satisfies this property.
Example :
Input:
S = "cba"
T = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A791
#ifdef A791

char* customSortString(char* S, char* T) {
	char *p=S;
	int i, j, k, len = strlen(T);
	char *ret = (char*)malloc(sizeof(char)*(len+1));
	ret[len] = '\0';
	char nums[26] = { 0 };
	for ( i = 0; i < len; i++)
	{
		nums[T[i] - 'a'] ++;
	}
	i = 0;
	while (*p)
	{
		j = nums[*p - 'a'];
		while (j > 0)
		{
			ret[i] = *p;
			i++;
			j--;
		}
		nums[*p - 'a'] = 0;
		p++;
	}
	for (k = 0; k < 26; k++)
	{
		j = nums[k];
		while (j>0)
		{
			ret[i] = k + 'a';
			i++;
			j--;
		}
	}
	return ret;
}

int main(){
	char *s = "cba";
	char *t = "abcd";
	printf("%s", customSortString(s, t));
	return 0;
}

#endif

