/*
 * @lc app=leetcode.cn id=剑指 Offer 33 lang=cpp
 * @lcpr version=21908
 *
 * [剑指 Offer 33] 二叉搜索树的后序遍历序列
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
    bool checkarray(int begin,int end,vector<int>& postorder)
    {
        if(begin>=end)
        return true;
        int root=postorder[end];
        int i=begin;
        while(postorder[i]<root)
        {
            i++;
        }
        while(i<end)
        {
            if(postorder[i++]<root)
             return false;
        }
        return checkarray(begin,i-1,postorder)&&checkarray(i,end-1,postorder);
        
    }
    bool verifyPostorder(vector<int>& postorder) {
       return checkarray(0,postorder.size()-1,postorder);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,6,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,6,5]\n
// @lcpr case=end

 */

