/*
669. Trim a Binary Search Tree
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
1
/ \
0   2

L = 1
R = 2

Output:
1
\
2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A669
#ifdef A669

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
	struct TreeNode* newRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (root->val <= L){

	}
	else if (root->val >=R)
	{

	}
	else{

	}
	return 
}

int main(){
	return 0;
}

#endif