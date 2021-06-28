
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;

/*
128. 最长连续序列
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto x:nums) 
            hash.insert(x);
        int ans = 0;
        while(!hash.empty())
        {
            int cur = *(hash.begin());
            int prev = cur - 1, next =cur +1;
            while(hash.count(next)){
                hash.erase(next++);
            }
            while(hash.count(prev)){
                hash.erase(prev--);
            }
            hash.erase(cur);
            ans  = max(ans, next-prev-1);

        }
        //[2147483647,-2147483648]
        return ans;

    }
};       