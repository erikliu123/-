#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：
*/
/*
较复杂的一个例子，照着这个思考：(()())(())(): 6+4+2=12
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int ans=0;
        vector<int> dp(n+1, 0);
        for(int i=0; i<n; i++)
        {
            if(s[i] == ')')
            {
                if(i>0 && s[i-1] == '('){
                    dp[i+1] = dp[i-1] + 2;
                }
                else if(i>0 && s[i-1] == ')'){//看看能不能找到前面有无匹配的一组括号(i-1 -dp[i]) + 1 = i -dp[i]-1, 是否OK
                    if((i - dp[i] - 1)>=0 && s[i -dp[i]-1] =='('){/**/
                        int x=dp[i-1-dp[i]];
                        // if(i >= (dp[i]+1))
                            dp[i+1] = dp[i] + 2 + x;
                        // else{
                        //     dp[i+1] = dp[i] + 2 ;
                        // }
                    }

                }
            }
        }
        for(auto x:dp){
            ans=max(ans, x);
        }
        return ans;

    }
};