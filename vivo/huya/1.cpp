#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
给你一个整数数组array和一个目标值target，请从数组中找出一个乘积最大的四元组，满足a + b + c + d = target，并返回它们的乘积。
如果没有满足条件的四元组，则返回0。

提示:
1<= nums.length <= 200
-109 <= nums[i]<= 109
-109 <= target <= 109
*/
class Solution {
public:
    vector<vector<int>> ans;
    int target, should_used;
    //ensure should_used>=2
    /*
        NOTICE: 更加普适的做法！
        used_nums表示现在遍历到了第几层，begin是开始遍历的数组下标, should_used表示要多少个数才能构成目标和,
    */
   long long maxAns = 0;
   
    void dfs(vector<int>& nums,  int used_nums, int cur_sum, int begin, vector<int>& temp)
    {
        if(should_used - used_nums == 2)/* 双指针到最后才使用 */
        {
            int l = begin, r = nums.size()-1;
            while(l<r)
            {
                if(r+1<nums.size() && nums[r+1] == nums[r]) {
                    --r;
                    continue;
                }
                int sum = cur_sum + nums[l] + nums[r];
                if(sum == target)
                {
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    long long sum = 1;
                    for(auto x:temp)
                    {
                        sum *= x;
                    }
                    if(sum > maxAns)
                    {
                        maxAns = sum;
                    }
                    //ans.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();

                }
                if(sum >= target){
                    --r;
                }
                else{
                    ++l;
                }
            }
            return ;

        }
        for(int i=begin; i<=(int)nums.size()-(should_used - used_nums); ++i)//i<=nums.size()-(should_used - used_nums);是无符号比较，不强制转换会导致非法访问！！
        {
            if(i!=begin && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            dfs(nums, used_nums+1, cur_sum+nums[i], i+1, temp);
            temp.pop_back();

        }

    }
    int maxProduct(vector<int>& nums, int target) {
        vector<int> temp;
        maxAns = 1ULL << 63;
        this->target = target;
        this->should_used = 4;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, 0, temp);
        if( maxAns ==( 1ULL << 63))
            return 0;
        else
            return maxAns;

    }
};