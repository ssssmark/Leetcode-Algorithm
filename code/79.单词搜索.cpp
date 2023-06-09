/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=21909
 *
 * [79] 单词搜索
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
   bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int str_idx, int i, int j) {
        if (str_idx == word.size()) return true;
        // 越界、被访问过、当前位置的字符不是word对应位置的字符
        if (i >= board.size() || i < 0 ||
            j >= board[0].size() || j < 0 ||
            visited[i][j] == true || board[i][j] != word[str_idx]) return false;

        visited[i][j] = true;
        if (dfs(board, visited, word, str_idx + 1, i + 1, j) ||
            dfs(board, visited, word, str_idx + 1, i - 1, j) ||
            dfs(board, visited, word, str_idx + 1, i, j + 1) ||
            dfs(board, visited, word, str_idx + 1, i, j - 1)) return true;
        visited[i][j] = false;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if(board[i][j]==word[0])
                {
                    if(dfs(board,visited,word,0,i,j))
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */

