#include <iostream>
#include <vector>

using namespace std;
/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        vector<int> dp(str.size()+1, 0);
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 1; i<str.size(); i++)
        {
            int num = (str[i-1]-'0')*10+str[i]-'0';
            if(num <= 25  && num>=10)//506
            {
                dp[i+1] = dp[i] + dp[i-1];
            }
            else{
                dp[i+1] = dp[i];
            }
        }
        return dp[str.size()];

    }
};