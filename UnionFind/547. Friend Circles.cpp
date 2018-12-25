/*******************************************************************
*  File        : 547. Friend Circles.cpp
*  Author      : H.Yin
*  Email       : csustyinhao@gmail.com
*  Created     : 2018-12-25 02:06:06(+0000)
*  Modified    : 2018-12-25 02:58:37(+0000)
*  GitHub      : https://github.com/H-Yin/CSLA
*  Description : 547. Friend Circles
*******************************************************************/
/*
547. Friend Circles
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. The 2nd student himself is in a friend circle. So return 2.

Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
*/

class Solution {
public:
    void display(vector<int> ids){
        for(int i=0; i < ids.size(); i++){
            printf("%d ", ids[i]);
        }
        printf("\n");
    }

    int find(vector<int> ids, int q){
        if(ids[q] == -1){
            return q;
        }
        ids[q] = find(ids, ids[q]);
        return ids[q];
    }
    
    int count(vector<int> ids){
        int c = 0;
        for(int i=0; i < ids.size(); i++){
            if(ids[i] == -1){
                c += 1;
            }
        }
        return c;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<int> ids(N, -1);
        for(int i=0; i< M.size(); i++){
            int a = find(ids, i);
             for(int j=0; j < M[i].size(); j++){
                 if (i != j && M[i][j] == 1){
                    // union
                    int b = find(ids, j);
                    if( b != a){
                        ids[b] = a;
                     }
                     // printf("%d,%d:", i, j);
                     // display(ids);
                 }
             }
        }
        return count(ids);
    }
};