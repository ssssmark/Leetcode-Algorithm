/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>& a, vector<int>& b){
            if(a[0] != b[0]) return a[0] > b[0];
            else return a[1] < b[1];
        });
        vector<vector<int>> res;
        for(auto p:people){
            if(res.size() > p[1])
             res.insert(res.begin()+p[1], p);
            else res.push_back(p);
        }
        return res;
    }
};
// @lc code=end

