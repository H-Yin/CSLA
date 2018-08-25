/*
213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

*/



// DP
class Solution {
public:
    int max(long long a,long long b){
        return a > b? a: b;
    }
    long long rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if (n == 1){
            return nums[0];
        }
        int max_1, max_2;
        vector<long> dp(n,0);
        dp[0] = 0;
        //以不含尾元素的情况
        for(int i = 0; i < n-1; i++){
            if(i == 0){
                dp[1] = nums[i];
            }else{
                dp[i+1] = max(dp[i-1]+nums[i], dp[i]);
            }
        }
        max_1 = dp[n-1];
        //含尾元素为开始的情况
        for(int i = 1; i < n; i++){
            if(i == 1){
                dp[1] = nums[i];
            }else{
                dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            }
        }
        max_2 = dp[n-1];
        
        return max(max_1,max_2);
    }
};
