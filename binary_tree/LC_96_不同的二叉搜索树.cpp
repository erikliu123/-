#include <iostream>
#include <vector>

using namespace std;
/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
*/
//思路：主要统计以1,2,...n,n+1为根节点时候的可能种类
class Solution {
public:
    int numTrees(int n) {
        //有点像费不拉起数列
        //f[0] = 1, f[1] = 1, f[2] = 2; f[3] = f[0] * f[2] +f [1] * f[1] +f[2] * f[0] 
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<i; j++)
                dp[i] += dp[j] * dp[i-1-j];
            
        }
        return dp[n];

    }
};