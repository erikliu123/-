#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

/*
132. 分割回文串 II
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。

*/
class Solution {
public:
    int minCut(string s) {
        int n =s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, 0));
        
        for(int len=1; len<=n; len++)
        {
            for(int start = 0; start+len<=n; start++)
            {
                if(len == 1) dp[start][start+len-1] = true;
                else if(len == 2)
                {
                      if(s[start] == s[start+len-1])  dp[start][start+len-1] = true;
                      else  dp[start][start+len-1] = false;
                }
                else //if(len % 2)
                {
                    if(s[start] == s[start+len-1])
                        dp[start][start+len-1] = dp[start+1][start+len-2];//不一定对，因为中间的不一定构成回文串？
                    else
                        dp[start][start+len-1] = false;
                    //else
                      //   dp[start][start+len-1] = dp[start+1][start+len-2]+2;
                        //dp[start][start+len-1] = 1;
                }
                // else{

                // }
            }

        }

        vector<int> f(n, INT_MAX);
        for(int i=0; i<n; i++)
        {
            if(dp[0][i])
            {
                f[i] = 0;
            }
            else{
                for(int j=0; j<i; j++)
                {
                    if(dp[j+1][i])
                    {
                        f[i] = min(f[i], f[j]+1);
                    }
                }
            }
            
        }
        return f[n-1];

        //f[i]

    }
};