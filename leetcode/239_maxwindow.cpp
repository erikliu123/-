

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int index = 0;
        for(auto x:nums)
        {
            if(!q.empty()  && (index-q.front()) >= k)//越界的元素扔掉
            {
                q.pop_front();
            }
            while(!q.empty()  && (x>=nums[q.back()])){//前面的不可能了，全都扔掉
                q.pop_back();
            }
            q.push_back(index);
            index++;
            if(index >= k)
            {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;

    }
};