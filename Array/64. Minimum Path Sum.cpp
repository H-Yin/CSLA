/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.


*/


/* 
 * path[i][j] Point(i,j) 的最小 Path
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[m-1].size();
        vector<vector<int>> path;
        path.resize(m, vector<int>(n));
        for(int i=0;i < m; i++){
            for(int j=0; j < n;j++){
                if(i== 0 && j ==0){
                    path[i][j] = grid[i][j];
                }else if(i == 0 && j > 0){
                    path[i][j] = path[i][j-1] + grid[i][j];
                }else if(j == 0 && i > 0){
                    path[i][j] = path[i-1][j] + grid[i][j];
                }else{
                    if(path[i][j-1] > path[i-1][j]){
                        path[i][j] = path[i-1][j] + grid[i][j];
                    }else{
                        path[i][j] = path[i][j-1] + grid[i][j];
                    }
                }
            }
        }
        return path[m-1][n-1];
    }
};
