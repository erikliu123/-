#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
题目描述：

给你一个整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1
 

提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 100
*/
class Solution {
public:
    int ans;
    void dfs(vector<int> &num, int begin, int cursum, int target, int left)
    {
        if(target == cursum){
            ans++;
            if(begin < num.size()  && num[begin] !=0) //对应0 0 0 1这样的数组，不应当当target = cursum时就立马退出
                return ;
        }
        
        for(int i=begin; i<num.size(); i++)
        {
            
            if(cursum + left >= target)
            {
                dfs(num, i+1, cursum + num[i], target, left-num[i]);
            }
            else break;
            left-=num[i];

        }

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto &i:nums) sum+=i;

        if( (sum -target) % 2  || abs(sum) < abs(target)){
            return 0;
        }
        int deduct = abs(sum-target) / 2;
        ans = 0;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, deduct, sum);
        return ans;


    }
};

int main()
{
    Solution a;
    vector<int> test_vec{1,1,1,1,1};
    int ans = a.findTargetSumWays(test_vec, 3);
    cout<<ans<<endl;
    return 0;
}