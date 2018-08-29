/*
40. Combination Sum II
DescriptionHintsSubmissionsDiscussSolution
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
// BT + sort + set
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> out;
        
        sort(candidates.begin(),candidates.end());
        
        combinationSumDFS(candidates,0,target,res,out);
        vector<vector<int>> ans;
        ans.assign(res.begin(),res.end());
        return ans;
    }
    void combinationSumDFS(vector<int>& candidates, int i, int target, set<vector<int>>& res, vector<int> out){
        if(target < 0){
            return;
        }else if(target == 0){
            res.insert(vector<int>(out));
        }else{
            for(int x = i; x<candidates.size();x++){
                out.push_back(candidates[x]);
                combinationSumDFS(candidates, x+1, target-candidates[x], res, out);
                out.pop_back();
            }
        }
    }
};
