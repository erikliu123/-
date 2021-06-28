#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

*/
class Solution {
public:
#ifdef N_N
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[i] >nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i<nums.size(); i++)
        {
            ans  = max(ans, dp[i]);
        }
        return ans;

    }
#else
/*
    执行用时：4 ms, 在所有 C++ 提交中击败了99.47%的用户
    内存消耗：10.4 MB, 在所有 C++ 提交中击败了17.83%的用户
*/
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cmp(nums.size(), INT_MAX);
        int ans = 1;
        cmp[0] = nums[0];
        for(int i = 1; i<nums.size(); i++)
        {
            int left = 0, right=ans;
            if(cmp[0] > nums[i]){//NOTICE：下面的else其实覆盖了if的逻辑，可以删去。。
                cmp[0] = nums[i];
            }
            else{
                //从左到右，找到第一个小于等于cmp元素的，进行替换
                while(left < right)
                {
                    int mid = (left + right)/2;
                    if(nums[i] > cmp[mid]){
                        left = mid + 1;
                    }
                    else{//NOTICE:总是担心这里会死循环。。
                        right = mid;
                    }

                }
                cmp[left] = nums[i];
                if(left >= ans){
                   ans++;
                }
                

            }
           
            

        }
        return ans;
        
    }

#endif
};

int main()
{
    vector<int> test{5,9,4,5,10,1,1,2};
    Solution a;
    a.lengthOfLIS(test);
    return 0;
}