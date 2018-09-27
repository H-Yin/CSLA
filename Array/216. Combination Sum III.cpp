/*
216. Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
    // 回溯 Backtracking
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSum3DFS(k, n, 1, res, out);
        return res;
    }
    
    void combinationSum3DFS(int k, int target, int next, vector<vector<int>> &res,vector<int> &out){
        if(k == 0){
            if(target == 0){
                res.push_back(out);
            }
        }else{
            for(int i = next; i<=9;i++){
                out.push_back(i);
                combinationSum3DFS(k-1, target-i, i+1, res,out);
                out.pop_back();
            }
        }
    }

};
