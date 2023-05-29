/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       vector<int> ans(nums.size());
       if(k==0)
       return;
       for(int i=0;i<nums.size();i++)
       {
           if(i+k<=nums.size()-1)
           {
               ans[i+k]=nums[i];
           }
           else{
               ans[(i+k)%nums.size()]=nums[i];
           }
          
       }
       ans.swap(nums);
       
    }
};
// @lc code=end

