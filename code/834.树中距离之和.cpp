/*
 * @lc app=leetcode.cn id=834 lang=cpp
 * @lcpr version=21910
 *
 * [834] 树中距离之和
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
    vector<int> ans, sz, dp;
    vector<vector<int>> graph;

    void dfs(int u, int f) {
        sz[u] = 1;
        dp[u] = 0;
        for (auto& v: graph[u]) {
            if (v == f) {
                continue;
            }
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    void dfs2(int u, int f) {
        ans[u] = dp[u];
        for (auto& v: graph[u]) {
            if (v == f) {
                continue;
            }
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];

            dfs2(v, u);

            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans.resize(n, 0);
        sz.resize(n, 0);
        dp.resize(n, 0);
        graph.resize(n, {});
        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }

};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

 */

