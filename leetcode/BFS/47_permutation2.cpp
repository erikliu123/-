#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
     vector<vector<int>> ans;
     void bfs(vector<int>& nums, int begin)
     {
         if(begin >= nums.size()-1)//无法继续交换了，结束
         {
             ans.push_back(nums);
             return ;
         }
         int last = nums[begin];
         for(int i=begin; i<nums.size(); i++)
         {
             
             int x=nums[i];
             if(i == begin || last !=nums[i]){
                nums.erase(nums.begin()+i);
                nums.insert(nums.begin()+begin, x);
                
                bfs(nums, begin+1);
                nums.erase(nums.begin()+begin);
                nums.insert(nums.begin()+i, x);
             }
             last = nums[i];
         }
         
     }
   
     vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bfs(nums, 0);
        return ans;
    }
};