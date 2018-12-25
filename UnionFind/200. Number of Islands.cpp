/*******************************************************************
*  File        : 547. Friend Circles.cpp
*  Author      : H.Yin
*  Email       : csustyinhao@gmail.com
*  Created     : 2018-12-25 02:06:06(+0000)
*  Modified    : 2018-12-25 02:58:37(+0000)
*  GitHub      : https://github.com/H-Yin/CSLA
*  Description : 200. Number of Islands
*******************************************************************/
/*
200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000

Output: 1

Example 2:
Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    void display(vector<int> ids){
        for(int i=0; i < ids.size(); i++){
            printf("%d ", ids[i]);
        }
        printf("\n");
    }
    // efficient method
    int find(vector<int> ids, int q){
        while(q != ids[q]) {
            ids[q] = ids[ids[q]];
            q = ids[q];
        }
        return q;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int sum=0, sub=0; // sum=number of 1; sub=number of union 1, count = sum - sub；
        int N = grid.size(), M = grid[0].size();
        vector<int> ids(N*M, 0);
        for(int i=0; i<N*M; i++){
            ids[i] = i;
        }
        
        for(int i=0; i< N; i++){
             for(int j=0; j < M; j++){
                 int p = i * M + j;
                 if(grid[i][j] == '1'){
                     sum++;
                     // top
                     if(i > 0 && grid[i-1][j] == '1'){
                         int a = find(ids, p-M);
                         int b = find(ids, p);
                         if (b != a){
                             ids[b] = a;
                             sub++;
                         }
                     }
                     // left
                     if(j > 0 && grid[i][j-1] == '1'){
                         int a = find(ids, p-1);
                         int b = find(ids, p);
                         if (b != a){
                             ids[b] = a;
                             sub++;
                         }
                     }
                 }else{
                     ids[p] = -1;
                 }
             }
        }
        return sum-sub;
    }
};