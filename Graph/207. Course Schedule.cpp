/*******************************************************************
*  File        : 207. Course Schedule.cpp
*  Author      : H.Yin
*  Email       : csustyinhao@gmail.com
*  Created     : 2019-01-04 07:00:57(+0000)
*  Modified    : 2019-01-04 07:02:09(+0000)
*  GitHub      : https://github.com/H-Yin/CSLA
*  Description : 207. Course Schedule
*******************************************************************/


/* 207. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> L, S, indegree(numCourses, 0), mark(numCourses, 0);
        int count = 0;

        for(int i =0 ; i< n ; i++){
            indegree[prerequisites[i].first] += 1;
        }

        for(int i =0 ; i< numCourses; i++){
            if(indegree[i] == 0){
                S.push_back(i);
            }
        }
        while(S.size() > 0){
            int v = S.back();
            if (mark[v] == 1){
                break;
            }
            S.pop_back(); 
            L.push_back(v);
            count++;
            mark[v] = 1;
            for(int i =0 ; i < n ; i++){
                if(prerequisites[i].second == v){
                    indegree[prerequisites[i].first] --;
                    if(indegree[prerequisites[i].first] == 0){
                        S.push_back(prerequisites[i].first);
                    }
                }
            }
        }

        return (count == numCourses);
    }
};
