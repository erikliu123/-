
#include <iostream>
#include <vector>

using namespace std;
/*
650. 只有两个键的键盘
最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：

Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
Paste (粘贴) : 你可以粘贴你上一次复制的字符。
给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。

示例 1:

输入: 3
输出: 3
解释:
最初, 我们只有一个字符 'A'。
第 1 步, 我们使用 Copy All 操作。
第 2 步, 我们使用 Paste 操作来获得 'AA'。
第 3 步, 我们使用 Paste 操作来获得 'AAA'。

说明:
n 的取值范围是 [1, 1000] 。
*/
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        //dp[0] = 1;
        dp[1] = 0;
         for(int i=2; i<=n; i++)
            dp[i] = i;
        for(int i=2; i<=n; i++)
        {
            for(int k=2; k<=i/2; k++)//NOTICE: 不可以把k<=sqrt(i) 比如18,可以选择9个2(AA)或者2个9(AAAAAAAAA);而k<=sqrt(i) 限制了2个9的选择
            {
                if(i%k == 0){
                    dp[i] = min(dp[i], (i/k)+dp[k]);
                }

            }
        }
        return dp[n];

    }
};