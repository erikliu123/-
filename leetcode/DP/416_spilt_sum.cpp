#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<bool> dp(10010, false);
        dp[0] = true;
        int sum=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
            sum+=nums[i];
        if(sum%2) return false;
        cout<<sum/2<<endl;
       for(int i=0; i<nums.size(); i++)
       {
           for(int v=sum/2; v>=nums[i]; v--)
           {
               dp[v] = dp[v] || dp[v-nums[i]];
           }
       }
       return dp[sum/2];

        
    }
};