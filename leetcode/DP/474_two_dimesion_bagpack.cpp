#include<iostream>
#include<vector>
using namespace std;
/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。


示例 1：

输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。


*/
//思路：简单的01背包问题的代价是背包重量，这个问题有两个代价，一个是1的重量（数目），一个是0的重量（数目）
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp =  vector<vector<int>>(m+1, vector<int>(n+1,0));
        vector<pair<int, int>> cost;
        for(int i = 0; i<strs.size(); i++)
        {
            int cnt[2] = {0,0};
            for(auto &x: strs[i]){
                cnt[x-'0']++;
            }
            cost.push_back(make_pair(cnt[0], cnt[1]));
        }
        for(int i = 0; i<strs.size(); i++)
        {
            for(int k = n; k>=cost[i].second; k--)
            {
                for(int v = m; v>=cost[i].first; v--)
                {
                    if(dp[v][k] < dp[v-cost[i].first][k-cost[i].second] + 1)
                        dp[v][k] = dp[v-cost[i].first][k-cost[i].second] + 1;
                }
            }
        }
        return dp[m][n];

            


    }
};