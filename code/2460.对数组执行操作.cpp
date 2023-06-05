/*
 * @lc app=leetcode.cn id=2460 lang=cpp
 * @lcpr version=21908
 *
 * [2460] 对数组执行操作
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
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
         for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                for(int j=i;j<n;j++)
                {
                    if(nums[j]!=0)
                    {
                        int tmp=nums[i];
                        nums[i]=nums[j];
                        nums[j]=tmp;
                         break;
                    }
                }

            }
        }
        return nums;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */

