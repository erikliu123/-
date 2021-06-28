#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
/*
1449. 数位成本和为目标值的最大数字
给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大 整数：

给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
总成本必须恰好等于 target 。
添加的数位中没有数字 0 。
由于答案可能会很大，请你以字符串形式返回。

如果按照上述要求无法得到任何整数，请你返回 "0" 。


示例 1：

输入：cost = [4,3,2,5,6,7,2,5,5], target = 9
输出："7772"
解释：添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772" 的代价为 2*3+ 3*1 = 9 。 "977" 也是满足要求的数字，但 "7772" 是较大的数字。
 数字     成本
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5

*/
class Solution {
public:
    bool mycmp(const string &a, const string &b)
    {
        string mid1, mid2;
        if(a.size() != b.size())
            return a.size() >b.size();
        else {
            return a > b;
        }

    }
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1, "");
        for(int i=0; i<cost.size(); i++)
        {
            for(int v=1; v<=target; v++)
            {
                if(v>=cost[i])
                {
                    //NOTICE:这里要判断dp[v-cost[i]]之前是不是已经装进去东西了（dp[v-cost[i]].size() > 0，对于dp[0]可以例外）。否则若dp[8]为空, dp[9] = "7" + dp[8]成立，将会有 dp[9] = "7" 的大问题
                    if(((v>cost[i] && dp[v-cost[i]].size() > 0)  || v==cost[i]) && mycmp(to_string(i+1) +dp[v-cost[i]], dp[v])){
                        dp[v] = to_string(i+1) + dp[v-cost[i]];
                        //cout<<v<<"\t"<<dp[v]<<endl;
                    }
                }
            }
        }
       // reverse(dp[target].begin(), dp[target].end());
       if(dp[target] == "") dp[target] = "0";
        return dp[target];

    }
};