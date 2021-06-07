#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/
class Solution {
public:
     vector<vector<int>> ans;
     set<vector<int>> lset;
     //回溯法
     void back_trace(vector<int>& nums, int begin, vector<int>& tmp)
     {
        //  if(begin >= nums.size())//无法继续交换了，结束
        //  {
        //      if(!lset.count(tmp)){
        //          lset.insert(tmp);
                 
        //      }
             
        //      return ;
        //  }
         ans.push_back(tmp);
       
         for(int i=begin; i<nums.size(); i++)
         {
           //加 或者 不加
           //back_trace(nums, i+1, tmp);
           if(i!=begin && nums[i] == nums[i-1]) continue;
           tmp.push_back(nums[i]);
            back_trace(nums, i+1, tmp);
           tmp.pop_back();
           
         }
         
     }
    //NOTICE: 思路最清晰的解法。如 1 1 2 2
    /*
    一开始是空集，先加入1个1, 2个1
    [] [1] [1 1]
    加入1个2
     [] [1] [1 1] [2] [1 2] [1 1 2]
    加入2个2后：
     [] [1] [1 1] [2] [1 2] [1 1 2] //[2] [1 2] [1 1 2]
     [] [1] [1 1] [2] [1 2] [1 1 2] [2 2] [1 2 2] [1 1 2 ]
    */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>());
        if( nums.empty() ) return ans;

        unordered_map<int, int> mp;
        for( int n : nums ) mp[n]++;

        for( auto itr=mp.begin(); itr!=mp.end(); itr++ ){
            int val=itr->first, times=itr->second;
            int size = ans.size();
            for( int i=0; i<times; i++ ){
                for( int j=0; j<size; j++ ){
                    ans.push_back(ans[j]);
                    ans.back().insert(ans.back().end(), i+1, val);//
                }
            }
        }

        return ans;
    }
    
    /*暴力回溯解法*/
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<int> tmp;
    //     back_trace(nums, 0, tmp);
    //     return ans;
    // }
};