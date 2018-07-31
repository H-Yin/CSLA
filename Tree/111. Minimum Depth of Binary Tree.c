/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A111
#ifdef A111

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode* root) {
	int left = 0, right = 0;
	if (root == NULL)
	{
		return 0;
	}
	left = minDepth(root->left) + 1;
	right = minDepth(root->right) + 1;
	if (root->left != NULL && root->right == NULL)
	{
		return left;
	}
	else if (root->left == NULL && root->right != NULL)
	{
		return right;
	}
	else{
		return left > right ? right : left;
	}
}

int main(){
	return 0;
}

#endif