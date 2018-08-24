/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Note: m and n will be at most 100.

Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
// DP
/*
             1   i=0 or j=0
            /
path[i][j] =    
            \path[i-1][j] + path[i][j-1]  i>0,j>0
*/
class Solution {
public:
    // 返回值防止溢出
    unsigned long long uniquePaths(int m, int n) {
        vector<vector<long long>> path;
        path.resize(m, vector<long long>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 or j == 0){
                    path[i][j] = 1ULL;
                }else {
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
        }
        cout<<path[m-1][n-1];
        return path[m-1][n-1];
    }
};
// Math
/*
C_{m-1+n-1}^{n-1}
*/
class Solution {
public:
    // 返回值防止溢出
    unsigned long long uniquePaths(int m, int n) {
        double res = 1;
        for(int i = 1;i <= n-1;i++){
            res = res *( m-1+i) / (double) i;
        }
        cout<<res;
        return res;
    }
};
