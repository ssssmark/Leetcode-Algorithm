/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=21908
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int ans=0;
    void backtrack(vector<int>&nums,int target,int start,int sum)
    {
        if(start==nums.size())
        {
            if(sum==target){
                ans++;
            }
        }
        
        else
        {
            backtrack(nums,target,start+1,sum+nums[start]);
            backtrack(nums,target,start+1,sum-nums[start]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums,target,0,0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

