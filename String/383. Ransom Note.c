/*
383. Ransom Note
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include <stdbool.h>

// #define A383
#ifdef A383


bool canConstruct(char* ransomNote, char* magazine) {
	int nums[26] = { 0 }, i = 0;
	char *p = NULL;
	for (p = magazine; *p != '\0'; p++){
		nums[*p - 'a']++;
	}
	for (p = ransomNote; *p != '\0'; p++){
		nums[*p - 'a']--;
	}
	for (i = 0; i < 26; i++)
	{
		if (nums[i] < 0){
			return false;
		}
	}
	return true;
}

int main(){
	printf("%d", canConstruct("aa","aab"));
	return 0;
}

#endif