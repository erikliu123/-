#include <iostream>
#include <vector>

using namespace std;
/*
题目描述：
一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：

'A' -> 1
'B' -> 2
...
'Z' -> 26
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：

"AAJF" ，将消息分组为 (1 1 10 6)
"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。

给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。

题目数据保证答案肯定是一个 32 位 的整数。

说明：
 1 <= s.length <= 100, s 只包含数字，并且可能包含前导零。
通过次数135,694提交次数458,738
*/
class Solution {
public:
    int ans;
    //暴力解法不可
    void bfs(string &s, int begin)
    {
        if(begin >= s.size()) {
            ans ++;
            return ;
        }
        if(s[begin] == '0') {
            return ;
            //bfs(s, begin + 1);
        }
        else{
            bfs(s, begin + 1);
            if(begin + 1 <s.size()){
                int num = (s[begin]- '0')*10 + s[begin + 1] - '0';
                if(num <= 26)  bfs(s, begin + 2);
            }
        }
    }
    int numDecodings(string s) {
        ans = 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=0; i< s.size(); i++)
        {
            if(s[i] == '0') {
                if(i < 1) return 0;
                if(s[i-1] > '0' && s[i-1] < '3') dp[i+1] = dp[i-1];//NOTICE: 100也要返回0
                else return 0;
            }
            else{
                dp[i+1] = dp[i];
                if(i>0 && s[i-1]!='0' &&((s[i-1]-'0')*10+s[i]-'0') < 27) dp[i+1] += dp[i-1];
            }
        }
        //bfs(s, 0);
        return dp[s.size()];
    }
};