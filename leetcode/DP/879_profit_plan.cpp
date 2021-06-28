
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
集团里有 n 名员工，他们可以完成各种各样的工作创造利润。
第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。
有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。


示例 1：
输入：n = 5, minProfit = 3, group = [2,2], profit = [2,3]
输出：2
解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
总的来说，有两种计划。

提示：
1 <= n <= 100
0 <= minProfit <= 100
1 <= group.length <= 100
1 <= group[i] <= 100
profit.length == group.length
0 <= profit[i] <= 100
*/

//实质dp[i][people][pro] = dp[i-1][people][pro] + dp[i-1][people-a[i]][pro-b[i]  (pro>=b[i])
//dp[i][people][pro] = dp[i-1][people][pro] + dp[i-1][people-a[i]][0]  (pro<b[i])

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int dp[101][101];
        memset(dp, 0 ,sizeof(dp));
        //dp[0][0] = 1;
        for(int i=0; i<=n; i++)//初始化状态很重要!!
            dp[i][0] = 1;
        for(int i=0; i<profit.size(); i++)
        {
            for(int people=n; people>=group[i]; people--)
            {
                for(int pro=minProfit; pro>=0; pro--){//NOTICE: for(int pro=0; pro<=minProfit; pro++){也可以pass, 因为profit不像人数作为限制，顺序正反均可以
                    // if(pro != minProfit)
                    //     dp[people][pro] = dp[people][pro+1];//
                    if(pro >= profit[i])
                        dp[people][pro] = (dp[people][pro] + dp[people-group[i]][pro-profit[i]])%1000000007;
                    else
                        dp[people][pro] =  (dp[people][pro] + dp[people-group[i]][0]) %1000000007;;

                    //printf("%d, %d [%d]\n", people, pro, dp[people][pro]);  
                }
                // if(profit[i] > minProfit) 
                //     for(int pro=minProfit; pro>=max(0, profit[i]); pro--)
                //         dp[people][pro] += dp[people-group[i]][0];
                // else{
                //     for(int pro=minProfit; pro>=profit[i]; pro--)
                //     {
                //         dp[people][pro] += dp[people-group[i]][pro-profit[i]];
                //         //cout<< dp[people][minProfit]<<"kkk \t";
                //     }
                // }
                //cout<< dp[people][minProfit]<<"\t";
                
            }

        }
        return dp[n][minProfit];

    }
};