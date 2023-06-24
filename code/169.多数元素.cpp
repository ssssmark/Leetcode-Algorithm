/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=21909
 *
 * [169] 多数元素
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
    int cal(vector<int>&nums,int target,int start,int end)
    {
        int ans=0;
        for(int i=start;i<=end;i++)
        {
            if(nums[i]==target)
            ans++;
        }
        return ans;
    }
    //分治思想
    int div(int start,int end,vector<int>&nums)
    {
        if(start==end)
        return nums[start];
        int mid=(start+end)/2;
        int leftmax=div(start,mid,nums);
        int rightmax=div(mid+1,end,nums);
        if(cal(nums,leftmax,start,end)>(end-start+1)/2)
        return leftmax;
        if(cal(nums,rightmax,start,end)>(end-start+1)/2)
        return rightmax;
        return -1;
    }
    int majorityElement(vector<int>& nums) {
        return div(0,nums.size()-1,nums);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */

