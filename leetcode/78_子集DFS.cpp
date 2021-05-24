#include<iostream>
#include<vector>
using namespace std;
/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
*/
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int begin, vector<int>& tmp)
    {
        if(begin > nums.size())  return ;
        ans.push_back(tmp);
        for(int i=begin; i<nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums, i+1, tmp);
            tmp.pop_back();
        }


    }
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        dfs(nums, 0, tmp);
        return ans;
    }
};