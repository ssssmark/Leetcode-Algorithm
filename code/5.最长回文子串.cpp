// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21908
 *
 * [5] 最长回文子串
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
    int dp[1000][1000]={};//dp[i][j]表示从第i个字母j结束的回文子串是否存在
    bool is_palindrome(int i,int j,string s)//判断从i到j字符串是否是回文串
    {
        bool flag=1;
        for(int start=i,end=j;start<end;start++,end--)
        {
            if(s[start]!=s[end])
            flag=0;
        }
        return flag;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1)
        return s;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;//所有长度为1的都是回文串
        }
        int begin=0;
        int maxlen=1;
        for(int L=2;L<=n;L++)//长度从2开始的回文串
        {
            for(int i=0;i<n;i++)
            {
                int j=L+i-1;
                if(j>=n)
                {
                    break;
                }
                if(s[i]!=s[j])
                {
                    dp[i][j]=0;
                }
                else{
                    if(j-i<=2)
                    {
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }

                if(dp[i][j]==1&&j-i+1>maxlen)
                {
                    maxlen=j-i+1;
                    begin=i;
                }
            }
        }
        return s.substr(begin,maxlen);

    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

