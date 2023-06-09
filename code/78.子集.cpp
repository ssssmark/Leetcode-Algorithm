/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
    vector<vector<int>> ans;
    vector<int>t;
    void backtrack(int i,vector<int>&path,vector<int>nums)
    {
        ans.push_back(path);
        for(int j=i;j<nums.size();j++)
        {
            path.push_back(nums[j]);
            backtrack(j+1,path,nums);
            path.pop_back();
        }
        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,t,nums);
        return ans;
         
    }
};
// @lc code=end

