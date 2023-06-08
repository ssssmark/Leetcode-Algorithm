// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=21909
 *
 * [77] 组合
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
    vector<int>temp;
    vector<vector<int>>ans;
    void backtrack(int n,int k,int pos)
    {
        if (temp.size()==k)
        {
            ans.push_back(temp);
        }
        for(int i=pos;i<=n;i++)
        {
            if(temp.empty()||i>temp.back())//去重，关键一步
            {
                 temp.push_back(i);
                 backtrack(n,k,pos+1);
                temp.pop_back();
            }
           
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n,k,1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

