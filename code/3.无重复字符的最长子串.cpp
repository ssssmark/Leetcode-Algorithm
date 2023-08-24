/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=21910
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        unordered_set<char> str;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (str.find(s[i]) != str.end()){
                str.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            str.insert(s[i]);
    }
        return maxStr;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

