/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start
class Solution {
public:
        vector<int> beautifulArray(int n) {
        vector<int> ans;
        if(n==1){
            ans.push_back(1);
            return ans;
        }
        int leftlen=(n+1)/2;
        int rightlen=n/2;
        vector<int>laaray=beautifulArray(leftlen);
        vector<int>rarray=beautifulArray(rightlen);
        for(int i=0;i<leftlen;i++)
        ans.push_back(2*laaray[i]-1);
        for(int j=0;j<rightlen;j++)
        ans.push_back(2*rarray[j]);
        return ans;
    }
   


};
// @lc code=end

