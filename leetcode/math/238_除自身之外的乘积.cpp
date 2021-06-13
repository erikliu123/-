
#include<iostream>
#include<vector>
using namespace std;

/*
238. 除自身以外数组的乘积
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。


示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
 
提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/

//采用分治思想
//output[i] = (a[0]*a[1]*...a[i-1])  * (a[i+1]*a[i+2]*...*a[n-1])
//令left[i] = a[0]*a[1]*...a[i-1], right[i] = (a[n-1]*a[n-1]*...*a[i+2]*a[i+1])

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*空间O(1), 时间O(N)的做法*/
        vector<int> left;
        if(nums.size() == 0) return left;
        left = vector<int>(nums.size(), 1);

        for(int i=1; i<nums.size(); i++)
        {
            left[i] = left[i-1] * nums[i-1];
            
        }
        int R=1;
        for(int i=nums.size() - 1; i>=0; i--)
        {
            left[i] = left[i] * R;
            R *= nums[i];
        }
        return left;

        /*空间O(n)的做法*/
        // vector<int> ans;
        // if(nums.size() == 0) return ans;
        // vector<int> left(nums.size(), 1), right(nums.size(), 1);
        // for(int i=1; i<nums.size(); i++)
        // {
        //     left[i] = left[i-1] * nums[i-1];
        //     right[nums.size()-i-1] = right[nums.size()-i] * nums[nums.size()-i];
        // }
        // for(int i=0; i<nums.size(); i++)
        //     ans.push_back(left[i] * right[i]);
        // return ans;
        
    }
};