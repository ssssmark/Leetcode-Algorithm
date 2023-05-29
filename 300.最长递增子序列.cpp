/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       if(n==0)
       return 0;
       int dp[n];
       memset(dp, 0, sizeof(dp));
       dp[0]=1;//以i结尾的最长递增子序列的长度
       for(int i=0;i<n;i++)
       {
          dp[i]=1;
        for(int j=0;j<i;j++)
        {
           if(nums[i]>nums[j])
           {
               dp[i]=max(dp[i],dp[j]+1);
           }
        }
       }
       int ans=0;
       for(int i=0;i<n;i++)
       {
          if(dp[i]>ans)
          ans=dp[i];
       }
       return ans;
    }
};
// @lc code=end

