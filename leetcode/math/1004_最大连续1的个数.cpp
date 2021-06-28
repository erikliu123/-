
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

 
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> zero;
        vector<int> dp(nums.size()+1, 0);
        int ans = 0;
        //zero.push(-1);
        int last_zero = -1;
        //
        int left=0, right=0, zero_cnt=0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] == 1){
                //right = i;
                ;
            }
            else{
                ++zero_cnt;
                if(zero_cnt > k){
                    while(left <= i && nums[left] == 1) ++left;
                    ++left;//NOTICE: 必须移动到过期0的后面！
                    --zero_cnt;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;


        /*比较笨拙的办法*/
        k=min(k, (int)nums.size());
        if(k>0){
            zero.push(-1);
        }
        int cnt=0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] == 1){
                dp[i+1] = ++cnt;
            }
            else{
                cnt = 0;
            }

        }
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] == 0){
                if(k>0){
                    int x = zero.front();
                    if(zero.size() == k){
                        zero.pop();
                    }
                    zero.push(i);
                    if(x >= 0 )
                    {
                        ans  = max(ans , i-x-1);
                    }
                    else
                        ans = i+1;
                }
                else if(k==0){
                    last_zero = i;
                }
                
            }
            else{
                if(!zero.empty())
                {
                    if(zero.front() >= 0)
                        ans  = max(ans , i-zero.front()+1 + dp[zero.front()]);
                    else
                        ans  = max(ans , i+1);
                }
                else{
                    ans  = max(ans , i-last_zero);
                }
            }


        }
        return ans;

    }
};