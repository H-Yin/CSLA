/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        combine(res, n, k, 0, 1, out);
        return res;
    }
    
    void combine(vector<vector<int>>& res, int n, int k, int i, int j, vector<int> &out){
        if(i == k){
            res.push_back(out);
        }else{
            for(int x=j; x <= n; x++){
                out.push_back(x);
                combine(res, n, k, i+1, x+1, out);
                out.pop_back();
            }
        }
    }
};
