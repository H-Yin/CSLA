/*
39. Combination Sum
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        combinationSumDFS(candidates,0,target,res,out);
        return res;
    }
    void combinationSumDFS(vector<int>& candidates, int i, int target, vector<vector<int>>& res, vector<int> out){
        if(target < 0){
            return;
        }else if(target == 0){
            res.push_back(vector<int>(out));
        }else{
            for(int x = i; x<candidates.size();x++){
                out.push_back(candidates[x]);
                combinationSumDFS(candidates, x, target-candidates[x], res, out);
                out.pop_back();
            }
        }
    }
};
