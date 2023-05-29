/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double quickpow(double x,long int N)
    {
        if(N==0)
        return 1.0;
        else
        {
            double ans=quickpow(x,N/2);
            if(N%2==0)
            return ans*ans;
            else return ans*ans*x;
        }
    }
    double myPow(double x, int n) {
        long int N=n;
        if(n>=0)
        return quickpow(x,N);
        else return 1/quickpow(x,-N);
    }
};
// @lc code=end

