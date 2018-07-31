/*
500. Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
*/
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// #define A500
#ifdef A500

char** findWords(char** words, int wordsSize, int* returnSize) {
	int rowNum[] = { 2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
		3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3 };
	int i, j, flag;
	char ** ret, a, b;
	*returnSize = 0;
	ret = (char**)malloc(sizeof(char*)*wordsSize);
	for (i = 0; i < wordsSize; i++){
		flag = 1;
		a = toLowerCase(words[i][0]);
		for (j = 1; words[i][j] != '\0'; j++){
			b = toLowerCase(words[i][j]);
			if (rowNum[a-'a'] != rowNum[b-'a']){
				flag = 0;
				break;
			}
		}
		if (flag == 1){
			ret[*returnSize] = (char*)malloc(sizeof(char)*(j + 1));
			strcpy(ret[*returnSize], words[i]);
			ret[*returnSize][j] = '\0';
			(*returnSize)++;
		}
	}
	return ret;
}

int main(){
	char *a[] = { "Alaska", "afsdghjkl", "qwertyuiop", "zxcvbnm" };
	int len = 0;
	char **ret = findWords(a, 4, &len);
	for (int i = 0; i < len; i++){
		printf("%s\n", ret[i]);
	}
	
	getchar();
	return 0;
}

#endif