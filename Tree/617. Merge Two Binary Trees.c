/*
617. Merge Two Binary Trees
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Input:
Tree 1                     Tree 2
1                         2
/ \                       / \
3   2                     1   3
/                           \   \
5                             4   7
Output:
Merged tree:
3
/ \
4   5
/ \   \
5   4   7

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A617
#ifdef A617

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
	struct TreeNode  *node = NULL;
	if (t1 == NULL && t2 == NULL){
		return node;
	}
	node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (t1 == NULL){
		node->val = t2->val;
		node->left = mergeTrees(NULL, t2->left);
		node->right = mergeTrees(NULL, t2->right);
	}
	else if (t2 == NULL)
	{
		node->val = t1->val;
		node->left = mergeTrees(t1->left, NULL);
		node->right = mergeTrees(t1->right, NULL);
	}
	else{
		node->val = t1->val + t2->val;
		node->left = mergeTrees(t1->left, t2->left);
		node->right = mergeTrees(t1->right, t2->right);
	}
	return node;
}

int main(){
	for (int i = 0; i < 100; i++){
		printf("%d, %d\n", i, i);
	}
	getchar();
	return 0;
}

#endif