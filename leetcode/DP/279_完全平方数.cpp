#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：
1 <= n <= 10^4
*/
//一个平方数可以被多次重复加入，所以是完全背包问题。
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX-1);
        dp[0] = 0;
        for(int i=1; i<=sqrt(n); i++)
        {
            //for(int k=n; k>=i*i; k++){
            for(int k=i*i; k<=n;  k++){
                dp[k]= min(dp[k], dp[k-i*i]+1);
            }

        }
        return dp[n];
        
    }
};