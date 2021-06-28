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
//NOTICE: 必须要两个dp数组！！

class Solution
{
public:
/*
添加备注

执行用时：8 ms, 在所有 C++ 提交中击败了79.17%的用户
内存消耗：10.5 MB, 在所有 C++ 提交中击败了85.12%的用户
*/
    int maxProfit(int k, vector<int> &prices)
    {
        vector<int> sell(k + 1, 0), buy(k + 1, INT_MIN);//sell[i]表示经过i笔交易后，此时卖出得到的股票利润； buy[i]sell[i]表示经过i笔交易后，此时持有股票剩下的利润

        for(int i=0; i<prices.size(); i++)
        {
            for(int j=1; j<=k; j++)
            {
                buy[j] = max(buy[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j-1] + prices[i]);
            }
        }
        // return ans;
        return sell[k];
    }
   
};