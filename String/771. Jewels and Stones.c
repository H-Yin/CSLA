/*
771. Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A771
#ifdef A771
/*
int numJewelsInStones(char* J, char* S) {
	int Jun[52] = {0}, sum=0;
	char *p = J;
	for (p = S; *p != '\0'; p++)
	{
		if (*p >= 'a' && *p <= 'z')
		{
			Jun[*p - 'a']++;
		}
		else{
			Jun[*p - 'A' + 26]++;
		}
	}
	for ( p=J; *p!= '\0'; p++)
	{
		if (*p >= 'a' && *p<='z')
		{
			sum += Jun[*p - 'a'];
		}
		else{
			sum += Jun[*p - 'A' + 26];
		}
	}
	return sum;
}
*/
/*
*/
int numJewelsInStones(char* J, char* S) {
	int jews = 0;
	int i, j;

	for (i = 0; J[i]; i++) {
		for (j = 0; S[j]; j++) {
			if (J[i] == S[j]){
				jews++;
				break;
			}
		}
	}
	return jews;
}


int main(){
	char a[] = "aA";
	char b[] = "aAAbbAbb";
	printf("%d", numJewelsInStones(a, b));
	getchar();
	return 0;
}

#endif