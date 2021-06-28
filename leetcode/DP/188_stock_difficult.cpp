#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
188. 买卖股票的最佳时机 IV
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。


示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
*/
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(k + 1, 0));

        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // dp[j+1][op] =  dp[j][op];
                if (prices[j] < prices[i])
                    for (int op = k - 1; op >= 0; --op)
                        dp[j + 1][op] = dp[j][op];
                else
                    for (int op = k - 1; op >= 0; --op)
                    {
                        dp[j + 1][op] = max(dp[j][op], dp[j + 1][op]);
                        dp[j + 1][op] = max(dp[j + 1][op], dp[i][op + 1] + prices[j] - prices[i]); //i->j天的盈利
                        //ans = max(ans, dp[j+1][op]);
                    }
            }
        }
        // return ans;
        return dp[n][0];
    }
    /* 一维的错误解法！！ */
    int maxProfit(int k, vector<int> &prices)
    {
        vector<int> dp(prices.size() + 1, 0);

        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // dp[j+1][op] =  dp[j][op];
                if (prices[j] < prices[i])
                    //for (int op = k - 1; op >= 0; --op)
                        dp[j + 1] = dp[j];
                else
                    for (int op = k - 1; op >= 0; --op)
                    {
                        dp[j + 1] = max(dp[j], dp[j + 1]);
                        dp[j + 1] = max(dp[j + 1], dp[i] + prices[j] - prices[i]); //i->j天的盈利, dp[i][op + 1]在执行这个循环前会更新成dp[i][op]，所以不可以
                        //ans = max(ans, dp[j+1][op]);
                    }
            }
        }
        // return ans;
        return dp[n];

    }
};