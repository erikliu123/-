#include<iostream>
#include<vector>
using namespace std;
/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

示例1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int sides = 0;
        for(int i=0; i<matrix.size(); i++)
        {
            int cnt = 0;
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == '1'){
                    //dp[i][j] = ++cnt;
                    if(i==0 || j==0){
                        dp[i][j] = 1;

                    }
                    else{
                        dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                    }
                    sides =  max(sides, dp[i][j]);
                }
                
            }
            
        }
        return sides * sides;

    }
};