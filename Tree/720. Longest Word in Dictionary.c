/*
720. Longest Word in Dictionary
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.
If there is no answer, return the empty string.
Example 1:
Input:
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation:
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input:
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation:
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:
All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A720
#ifdef A720

struct dictTree{
	struct dictTree *child[26];
	int number; // 前缀个数
	char letter;
	int isWord; // 是否构词
	// int wordCount; // 构词个数
};

struct dictTree * createDictTree(char** words, int wordsSize){
	int i, j, k;
	struct dictTree *root = (struct dictTree *)malloc(sizeof(struct dictTree));
	struct dictTree *temp= NULL, *temproot = NULL;
	memset(root->child, 0, sizeof(root->child));
	for (i = 0; i < wordsSize; i++)
	{
		temproot = root;
		for ( j = 0; words[i][j] !='\0' ; j++)
		{
			if (temproot->child[words[i][j] - 'a'] == NULL){
				temp = (struct dictTree *)malloc(sizeof(struct dictTree));
				memset(temp->child, 0, sizeof(temp->child));
				temp->number = 1;
				temp->isWord = 0;
				temproot->child[words[i][j] - 'a'] = temp;
			}
			else{
				temp = temproot->child[words[i][j] - 'a'];
				temp->number++;
			}
			temproot = temp;
		}
		temp->isWord = true;
	}
	return root;
}

void printDictTree(struct dictTree * root){
	if (root == NULL)
	{
		printf("\n");
		return;
	}
	if (root->number > 0){
		printf("%d\n", root->number);
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (root->child[i] != NULL)
		{
			printf("%c:", i + 'a');
			printDictTree(root->child[i]);
		}
	}
}

char* longestWord(char** words, int wordsSize) {
	struct dictTree * root = createDictTree(words, wordsSize);
	printDictTree(root);
	return NULL;
}

int main(){
	char *a[] = { "w", "wo", "wor", "worl", "world" };
	longestWord(a, 5);
	return 0;
}

#endif