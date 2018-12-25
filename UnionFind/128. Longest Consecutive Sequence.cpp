/*******************************************************************
*  File        : 547. Friend Circles.cpp
*  Author      : H.Yin
*  Email       : csustyinhao@gmail.com
*  Created     : 2018-12-25 02:06:06(+0000)
*  Modified    : 2018-12-25 02:58:37(+0000)
*  GitHub      : https://github.com/H-Yin/CSLA
*  Description : 128. Longest Consecutive Sequence
*******************************************************************/
/*
128. Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    
    void display(vector<int> ids){
        for(int i=0; i < ids.size(); i++){
            printf("%d ", ids[i]);
        }
        printf("\n");
    }
    
    int max_len = 0;
    
    int find(vector<int>& ids, int q){
        while(ids[q] != q){
            ids[q] = ids[ids[q]];
            q = ids[q];
        }
        return q;
    }
    
    void dounion(vector<int>& ids, vector<int>& size, int a, int b){
        int p = find(ids, a); 
        int q = find(ids, b);
        if( p != q){
            if(size[p] > size[q]){
                ids[q] = p;
                size[p] += size[q];
                max_len = max(size[p], max_len);
            }else{
                ids[p] = q;
                size[q] += size[p];
                max_len = max(size[q], max_len);
            }
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int N = nums.size();
        vector<int> ids(N, -1);
        vector<int> size(N, 1);
        map<int, int> index_map;
        for(int i=0; i<N; i++){
            // de-duplication
            if(index_map.count(nums[i]) < 1){
                ids[i] = i;
                index_map[nums[i]] = i;
            }
        }
        max_len = size[0];
        display(ids);
        for(int i=0; i<N; i++){
            if(ids[i] == -1) continue; // skip duplicate elements 
            if(index_map.count(nums[i]-1) > 0){
                dounion(ids, size, index_map[nums[i]-1], i);
            }
            if(index_map.count(nums[i]+1) > 0){
                dounion(ids, size, i, index_map[nums[i]+1]);
            }
            // printf("%d: ", nums[i]);
            // display(ids);
            // printf("--------------------------------------------");
            // display(size);
        }
        return max_len;
    }
};