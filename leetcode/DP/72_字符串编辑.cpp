#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符


示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/

/*
NOTICE:思路
设有字符串a，b；假设我们只操作b
若删除一个字符才构成b，其实是往a添加一个字符 dp[i-1][j] + 1
若在尾部新增一个字符才构成b， dp[i][j-1] + 1
若是替换b的最后一个字符为a的最后一个字符
    1. a[a.tail] = b[b.tail] 则编译距离 dp[i-1][j-1] 
    2. a[a.tail] = b[b.tail] 则 dp[i-1][j-1] + 1 

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, INT_MAX-1));
        int n = word1.size(), m = word2.size();
        dp[0][0] = 0;
        for(int i = 0; i<n; i++)
            dp[i+1][0] = i+1;
        for(int i = 0; i<m; i++)
            dp[0][i+1] = i+1;
        for(int i =0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                 
               
                if(word1[i] == word2[j])
                {
                    dp[i+1][j+1] = min(dp[i][j], dp[i+1][j+1]);
                }
                else{
                    dp[i+1][j+1] = min(min(dp[i+1][j], dp[i][j+1]), dp[i][j]) + 1; 
                   
                }
            }
        }
        return dp[n][m];

    }
};