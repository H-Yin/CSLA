/*
387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Examples:
s = "leetcode"
return 0.
s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A387
#ifdef A387

int firstUniqChar(char* s) {
	int i = 0, ret = -1;
	int nums[26] = { 0 };
	for (i = 0; s[i] != '\0'; i++){
		nums[s[i] - 'a']++;
	}
	for (i = 0;  s[i] != '\0'; i++){
		if (nums[s[i]-'a'] == 1){
			return i;
		}
	}
	return ret;
}

int main(){

	printf("==:%d\n", firstUniqChar("eee"));
	return 0;
}

#endif