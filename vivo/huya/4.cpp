#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
2n个人排成一列进入剧院。入场费为1元。2n个人中有n个人有一张1元纸币，n个人有一张2元纸币。开始售票员手上没有任何零钱，
问有多少种排队方法使得每当有人用2元纸币买票时，售票员总有1元可以找零?

卡塔兰数经典题目。。。
*/
class Solution {
public:
    long long DifferentQueues(int n) {
        //f[0] = 1, f[1] = 1, f[2] = 2; f[3] = f[0] * f[2] +f [1] * f[1] +f[2] * f[0] 
        vector<long long> dp(n+1, 0);
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