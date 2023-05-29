/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    void quicksort(vector<int>&nums,int left,int right,int k)
    {
        if(left>=right)
        return;
        int pivot=nums[left];
        int i=left,j=right;
        while(i<j)
        {
            while(i<j&&nums[j]>=pivot) j--;
            swap(nums[i],nums[j]);
            while(i<j&&nums[i]<=pivot) i++;
            swap(nums[i], nums[j]);  
        }
        if(nums.size()-i<k)
           quicksort(nums,left,i-1,k);
        else
        quicksort(nums,i+1,right,k);  
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        quicksort(nums, 0, n-1, k);
        return nums[n-k];
    }
};
// @lc code=end

