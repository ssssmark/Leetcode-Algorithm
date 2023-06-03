/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=21908
 *
 * [17] 电话号码的字母组合
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
    string temp;
    vector<string> board = {"", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void backtrack(int pos,string digits)
    {
        if(pos==digits.length())
        {
            ans.push_back(temp);
            return; 
        }
        int num = digits[pos] - '0';//表示现在输入的数
        for(int i=0;i<board[num].length();i++)//遍历这个数表示的所有字母
        {
            temp.push_back(board[num][i]);
            backtrack(pos+1,digits);
            temp.pop_back();//回溯到上一层
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        backtrack(0,digits);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

