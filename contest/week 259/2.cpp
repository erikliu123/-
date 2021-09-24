#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
漂亮值
给你一个下标从 0 开始的整数数组 nums 。对于每个下标 i（1 <= i <= nums.length - 2），nums[i] 的 美丽值 等于：

2，对于所有 0 <= j < i 且 i < k <= nums.length - 1 ，满足 nums[j] < nums[i] < nums[k]
1，如果满足 nums[i - 1] < nums[i] < nums[i + 1] ，且不满足前面的条件
0，如果上述条件全部不满足
返回符合 1 <= i <= nums.length - 2 的所有 nums[i] 的 美丽值的总和 。

*/
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        //有序的判断
        vector<int> copyNum = nums;
        unordered_map<int, int> mHash;
        sort(copyNum.begin(), copyNum.end());
        int maxn = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            mHash[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && ((i+1)<nums.size()))
            {
                if(nums[i] == copyNum[i] && nums[i] > maxn)//nums[i] == copyNum[i] 表示nums[i]的位置正确
                {
                   
                    if(mHash[nums[i]] == 1)//后面没有相同的数了 如1 2 3 3 4 的3不能+2
                        ans += 2;
                    else if(nums[i-1] < nums[i] && nums[i] < nums[i+1])
                        ans++;
                }
                else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]){
                    ans++;
                }
            }

            if(nums[i] > maxn)
            {
                maxn = nums[i];
            }

        }
        return ans;
    }
};