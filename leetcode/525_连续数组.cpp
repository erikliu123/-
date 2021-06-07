
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

示例 1:
输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 

提示：
1 <= nums.length <= 105
nums[i] 不是 0 就是 1

*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        //int left = 0, right = 1;//nums.size();
        unordered_map<int, vector<int>> sum_map;//sum对应的下标
        int index = 0;
         sum_map[0].push_back(-1);//NOTICE:初始值也需要注意，否则[0,1,0,1]的结果是2
        for(auto &i:nums)
        {
            sum += (i==0 ? -1 : 1);
            sum_map[sum].push_back(index);
            //cout<<sum<<"\t"<<index<<endl;
            index++;

        }
       
        for(auto &i: sum_map)
        {
            int dist=i.second[i.second.size()-1] - i.second[0];
            if(dist > ans)
                ans = dist;
        }
        return ans;
        // while(left < right && left>=0 && right<nums.size())
        // {
        //     while(left>=0 && right<nums.size() && nums[left] != nums[right]){
        //         ans += 2;
        //         --left;
        //         ++right;
        //     }
        //     ++left;
        //     ++right;

        // }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> num{1,0,1,1,1,1,0};
    cout<<a.findMaxLength(num)<<endl;
    return 0;
}