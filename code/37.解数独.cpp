/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=21908
 *
 * [37] 解数独
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
bool isValid(vector<vector<char>> &board, int row, int col, char val) {

        for (int j = 0; j < board.size(); ++j) {  //判断同一行内是否有重复数字
            if (board[row][j] == val) return false;
        }
        
        for (int i = 0; i < board.size(); ++i) {  //判断同一列内是否有重复数字
            if (board[i][col] == val) return false;
        }
        
        // 计算所在九宫格的左上角坐标。(注意索引从0开始)
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == val) return false;
            }
        }
        return true;       //如果和已存在数字不冲突，可以填入！
    }
    bool backtrack(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                continue;
                else{
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(isValid(board,i,j,ch)==true)
                        {
                            board[i][j]=ch;
                            bool finish=backtrack(board);//此时如果布尔值为true，代表已经遍历完所有的棋盘并填入，可以返回
                            if(finish)
                            return true;
                        
                        } 
                    }
                     //填完1~9都不行，回溯并返回上一层。让上一个空尝试别的数字。
                        board[i][j] = '.';  // 回溯复原
                        return false;   
                }
            }
        }
        //遍历了所有网格，说明所有空都填好了，可以返回了。
        return true;  //这是最底层的返回值。
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

