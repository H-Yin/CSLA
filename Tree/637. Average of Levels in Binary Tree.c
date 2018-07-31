/*
637. Average of Levels in Binary Tree
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
3
/ \
9  20
/  \
15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// #define A637
#ifdef A637

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


#define MAX(a,b) ((a)>(b)?(a):(b))
int getHeight(struct TreeNode* root){
	if (root == NULL){
		return 0;
	}
	return MAX(getHeight(root->left), getHeight(root->right)) + 1;
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
	int *sum, *nodes;
	double *ret;

	return ret;
}

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