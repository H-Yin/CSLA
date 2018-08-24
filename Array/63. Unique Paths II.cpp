/*
63. Unique Paths II
DescriptionHintsSubmissionsDiscussSolution
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
//DP
class Solution {
public:
    unsigned long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[m-1].size();
        
        vector<vector<long long>> path;
        path.resize(m, vector<long long>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    path[i][j] = 0ULL;                
                }else if(i == 0 && j == 0){
                    path[i][j] = 1ULL;
                }else if(i == 0){
                    path[i][j] = path[i][j-1];
                }else if(j == 0){
                     path[i][j] = path[i-1][j];
                }else{
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
        }
        cout<<path[m-1][n-1];
        return path[m-1][n-1];
    }
};
