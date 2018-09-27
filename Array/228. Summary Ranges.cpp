/*
228. Summary Ranges
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = nums.size();
        // 考虑输入为空
        if(len < 1){
            return res;
        }
        int start = nums[0], end;
        
        for(int i = 1;i <= len;i++){
            // 1: 前后两个数差1；2：考虑最后一个数的情况
            if((i < len && nums[i] - nums[i-1] != 1) || i== len){
                ostringstream ss;
                end = nums[i-1];
                if(start == end){
                    ss << start;
                }else{
                    ss << start << "->" << end;
                }
                res.push_back(ss.str());
                start = nums[i];
            }
        }
        return res;
    }
};
