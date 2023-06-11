/*
 * @lc app=leetcode.cn id=64 lang=cpp
 * @lcpr version=21909
 *
 * [64] 最小路径和
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution {
public:
    int dp[210][210];//dp[i，j]表示从[i,j]到终点的最小路径长度
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            dp[i][j]=99999;
        }
        dp[m-1][n-1]=grid[m-1][n-1];
       for(int i=m-1;i>=0;i--)
       {
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1&&j==n-1)
            dp[i][j]=grid[i][j];
            else {
                if(i==m-1&&j<n-1)
                {
                    dp[i][j]=min(dp[i][j],grid[i][j]+dp[i][j+1]);
                }
                else if(i<m-1&&j==n-1)
                {
                    dp[i][j]=min(dp[i][j],grid[i][j]+dp[i+1][j]);
                }
                else{
                    int temp=min(dp[i][j+1],dp[i+1][j])+grid[i][j];
                    dp[i][j]=min(dp[i][j],temp);
                }
            }
            
        }
       }
        return dp[0][0];
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */

