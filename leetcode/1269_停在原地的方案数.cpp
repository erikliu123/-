#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。
每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。
给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。
由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

 
示例 1：

输入：steps = 3, arrLen = 2
输出：4
解释：3 步后，总共有 4 种不同的方法可以停在索引 0 处。
向右，向左，不动
不动，向右，向左
向右，不动，向左
不动，不动，不动


提示：
1 <= steps <= 500
1 <= arrLen <= 10^6

*/
class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1, vector<int>(steps+2,0));//(steps+1, 0));  NOTICE:不能是steps+1
        dp[0][0] = 1;
        for(int i=1; i<=steps; i++){
            for(int j=min(arrLen, i); j>=0; j--){
                dp[i][j] = dp[i-1][j];
                if(j>=1)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1])%1000000007;
                if(j+1<arrLen)
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1])%1000000007;
                // for(int k=1; k<=i; k++){
                //     if(j>=k && i>=k)
                //         dp[i][j] = (dp[i][j] + dp[i-k][j-k])%1000000007;
                //     if(j+k<arrLen && i>=k)
                //         dp[i][j] = (dp[i][j] + dp[i-k][j+k])%1000000007;
                // }
                // if(j>0){
                //     dp[i][j] += dp[i-1][j-1];//经过i-1步到j-1
                // }
                // if(j+1 < arrLen){
                //     dp[i][j] += dp[i-1][j+1];//经过i-1步到j-1
                // }
                //cout<<dp[i][j]<<" \t";
                 
            }
            //cout<<endl;
           
        }
        return dp[steps][0];


    }
};

int main()
{
    Solution a;
    cout<<a.numWays(3,2)<<endl;
    cout<<a.numWays(5,100)<<endl;
    cout<<a.numWays(400,100)<<endl;
    return 0;
}