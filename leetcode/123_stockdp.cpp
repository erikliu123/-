
#include<iostream>
#include<vector>
using namespace std;

/*
题目描述：
123. 买卖股票的最佳时机 III
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 
示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

提示：
1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

/*
测试结果：
执行用时：160 ms, 在所有 C++ 提交中击败了59.19%的用户
内存消耗：79.5 MB, 在所有 C++ 提交中击败了36.66%的用户
*/
class Solution {
public:
    //其实就是分成两部分[0,i]天的最大利润 + [i+1,n]天能获得的最大利润
    //前一部分就是股票问题1的逻辑，后一部分也不难求，一次遍历可以获得结果
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0), back_dp(prices.size()+1, 0);
        int ans = 0, min=prices[0], maxm=prices[prices.size()-1];
        for(int i=0; i<prices.size(); i++)
        {
            if(i>0)
                dp[i] = dp[i-1];
            if(dp[i] < (prices[i]-min))
            {
                dp[i] = prices[i] - min;
            }
            if(min > prices[i]) min = prices[i];
            
        }
        
        for(int i=prices.size()-1; i>=0; i--)
        {
            if(i != prices.size()-1)
                back_dp[i] = back_dp[i+1];
            if(back_dp[i] < (maxm - prices[i]))
            {
                back_dp[i] = maxm - prices[i];
            }
            if(maxm < prices[i]) maxm = prices[i];

        }
        ans = back_dp[0];
        for(int i=0; i<prices.size(); i++)
        {
            ans = max(ans, dp[i]+back_dp[i+1]);
        }
        return ans;
       

    }
};