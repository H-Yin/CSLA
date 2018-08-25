/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root== NULL){
            return 0;
        }else{
            int tmp = 0;
            if(root->left != NULL){
                tmp += rob(root->left->left)+rob(root->left->right);
            }
            if(root->right != NULL){
                tmp += rob(root->right->left)+rob(root->right->right);
            }
            return max(root->val+tmp, rob(root->left)+rob(root->right));
        }
    } 
};
/*
// 优化的方法
class Solution {
public:
   int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        vector<int> result = helper(root);
        return max(result[0], result[1]);
    }
    
    vector<int> helper(TreeNode* node) {
        if (node == NULL) {
            return vector<int>(2,0);
        }
        
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);
        vector<int> now = vector<int>(2,0);
        now[0] = max(left[0], left[1]) + max(right[0], right[1]); // 不选当前节点
        now[1] = left[0] + right[0] + node->val; // 选 当前节点

        return now;
    }
};
*/
