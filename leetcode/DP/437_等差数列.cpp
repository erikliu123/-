#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for(int i=2; i<nums.size(); i++)
        {
            if(2*nums[i-1] == nums[i-2]+nums[i])
            {
                ++cnt;
                ans+=cnt;
            }
            else{
                cnt = 0;

            }
        }
        return ans;

    }
};