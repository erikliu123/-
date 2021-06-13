#include<iostream>
#include<vector>
using namespace std;

/*
260. 只出现一次的数字 III
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for(auto x:nums) 
            temp ^= x;
        unsigned int mask = 1;
        while((temp & mask) ==0){
            mask <<= 1;
        }
        //
        int temp2 = 0;
        for(auto x:nums)
        {
            if(x & mask)
            {
                temp2 ^= x;
            }
            
        }
        return vector<int>{temp2, temp^temp2};
        


        // set<int> num_set;
        // vector<int> ans;
        // for(auto x:nums)
        // {
        //     if(num_set.count(x)){
        //         num_set.erase(x);
        //     }
        //     else{
        //         num_set.insert(x);
        //     }
        // }
        // for(auto x:num_set){
        //     ans.push_back(x);
        // }
        // return ans;

    }
};