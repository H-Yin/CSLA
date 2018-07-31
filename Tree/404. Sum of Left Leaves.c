/*
404. Sum of Left Leaves
Find the sum of all left leaves in a given binary tree.
Example:
	3
   / \
  9  20
    /  \
   15   7
There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


// #define A404
#ifdef A404


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	else{
		if (root->left == NULL){
			return 0 + sumOfLeftLeaves(root->right);
		}
		if (root->left->left == NULL && root->left->right == NULL)
		{
			return root->left->val + sumOfLeftLeaves(root->right);
		}
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
}

int main(){
	for (int i = 0; i < 100; i++){
		printf("%d, %d\n", i, i);
	}
	return 0;
}

#endif