/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int num=0;
        vector<int> dp(amount + 1, amount+1 );//dp[n]代表构成金额n的最少零钱数量
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                  if(coins[j]<=i)
                  dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
            
        }
        if(dp[amount]>amount)
        return -1;
        return dp[amount];
    }
};
// @lc code=end

