/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strn=to_string(n);
        int i=1;
       while(i<strn.length()&&strn[i-1]<=strn[i])
       i++;//找到第一个不满足递增的位置
       if(i<strn.length())
       {
         while (i > 0 && strn[i - 1] > strn[i]) {
                strn[i - 1] -= 1;
                i -= 1;
            }
        i++;
        for(i;i<strn.length();++i)
        strn[i]='9';
       }
        
    return stoi(strn);



    }
};
// @lc code=end

