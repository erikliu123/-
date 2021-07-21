#include <iostream>
#include <vector>

using namespace std;
/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...

*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0] = true;
        if(s1.size()+s2.size() != s3.size())
            return false;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] == s3[i]) 
                dp[i+1][0] = true;
            else 
                break;
        }
        for(int i=0; i<s2.size(); i++){
            if(s2[i] == s3[i]) 
                dp[0][i+1] = true;
            else 
                break;
        }
        for(int i=0; i<s1.size(); i++)
        {
            // if(s1[i] == s3[i]) 
            //     dp[i+1][0] = dp[i][0];
            for(int j=0; j<s2.size(); j++)
            {
                if(s1[i] == s3[i+j+1])//最后一个字符是s1的
                {
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1];//dp[0][x]
                }
                if(s2[j] == s3[i+j+1])//最后一个字符是s2的
                {
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i+1][j];//选择谁匹配了？

                }

            }
        }
        return dp[s1.size()][s2.size()];

    }
};