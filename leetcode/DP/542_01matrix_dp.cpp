#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
/*
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为1。
*/

/*
    执行用时：48 ms, 在所有 C++ 提交中击败了99.88%的用户
    内存消耗：25.6 MB, 在所有 C++ 提交中击败了51.46%的用户

*/

//从右下方向遍历，再从左上方向遍历，取最小值即可
class Solution {
public:
    queue<pair<int, int>> pos;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size() , INT_MAX-1));
        int depth=0;
        int rows = mat.size(), cols = mat[0].size();
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++) 
            {
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(i > 0)
                        dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                     if(j > 0)
                    {
                         dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                    }
                }
                    
            }
        }

        for(int i=rows-1; i>=0; i--)
        {
            for(int j=cols-1; j>=0; j--)
            {
                if(mat[i][j] != 0){
                    if(i != rows-1)
                        dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                     if(j != cols-1)
                    {
                         dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                    }
                }
            }
        }
        return dp;


    }
};