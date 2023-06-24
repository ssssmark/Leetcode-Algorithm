/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=21909
 *
 * [102] 二叉树的层序遍历
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

/*struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
        {
            return ans;
        }
        queue<TreeNode*>a;
        a.push(root);
        while(!a.empty())
        {
            int size=a.size();
            ans.push_back(vector<int>());
            for(int i=1;i<=size;i++)
            {
                TreeNode* node=a.front();
                ans.back().push_back(node->val);
                a.pop();
                if(node->left)
                a.push(node->left);
                if(node->right)
                a.push(node->right);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

