/*
 * @lc app=leetcode.cn id=397 lang=cpp
 * @lcpr version=21909
 *
 * [397] 整数替换
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
    
   int integerReplacement(int n) {
        return dg(n);
    }

    long long dg(long long n){
        if(n==1)return 0;
        if(n==2)return 1;
        if(n%2==0) return 1+dg(n/2);
        else return 1+min(dg(n+1),dg(n-1));
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

