/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=21909
 *
 * [122] 买卖股票的最佳时机 II
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
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int flag=0;
        int sum=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]<=prices[i-1])
            {
                continue;
            }
            else{
                sum+=prices[i]-prices[i-1];
            }
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

