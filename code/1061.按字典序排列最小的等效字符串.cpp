/*
 * @lc app=leetcode.cn id=1061 lang=cpp
 * @lcpr version=21911
 *
 * [1061] 按字典序排列最小的等效字符串
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

class unionfind {
public:
    vector<int> parent;
    int find(int p) {
        if(p == parent[p]) return p;
        parent[p] = find(parent[p]);
        return parent[p];
    }
    unionfind() {
        for(int i = 0; i < 26; i++) {
            parent.push_back(i);
        }
    }
    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot) return ;
        if(pRoot < qRoot) parent[qRoot] = pRoot;
        else parent[pRoot] = qRoot;//让字典序较小的字母作为根节点
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unionfind u;
        for(int i = 0; i < s1.size(); i++) {
            int p = s1[i] - 'a', q = s2[i] - 'a';
            u.unionElements(p, q);
        }

        string res;

        for(int i = 0; i < baseStr.size(); i++) {
            int an = baseStr[i] - 'a';
            int need = u.find(an);
            res.push_back(need + 'a');
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "parker"\n"morris"\n"parser"\n
// @lcpr case=end

// @lcpr case=start
// "hello"\n"world"\n"hold"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"programs"\n"sourcecode"\n
// @lcpr case=end

 */

