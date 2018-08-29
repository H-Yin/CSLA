/*
79. Word Search
DescriptionHintsSubmissionsDiscussSolution
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> flag(m,vector<bool>(n,false));
        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                bool temp = DFS(board, word, 0, x, y, flag);
                if(temp){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool DFS(vector<vector<char>>& board, string word,int k, int x, int y, vector<vector<bool>> flag){
        int m = board.size();
        int n = board[0].size();
        if(x <0 || x >=m || y <0 || y>=n || k == word.length()){
            return false;
        }
        if(flag[x][y] != true && board[x][y] == word[k]){
            flag[x][y] = true;
            if(k+1 == word.length()){
                return true;
            }
            bool temp =  DFS(board,word, k+1, x+1, y, flag)
                || DFS(board,word, k+1, x, y+1, flag)
                || DFS(board,word, k+1, x-1, y, flag)
                || DFS(board,word, k+1, x, y-1, flag);
            if(!temp){
                flag[x][y] = false;
            }
            return temp;
        }
        return false;
    }
};
