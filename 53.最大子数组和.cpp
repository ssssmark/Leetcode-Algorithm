/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int n=nums.size();
        int b=0,sum=nums[0];
        for(int i=0;i<n;i++)
        {
            if(b>0)
            b+=nums[i];
            else
            b=nums[i];
            if(b>sum)
            sum=b;
        }
        return sum;
    }
};
// @lc code=end

