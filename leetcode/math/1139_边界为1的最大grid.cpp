
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
1139. 最大的以 1 为边界的正方形
给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。

*/
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>> sum[4];
        int n = grid.size();
        int m = grid[0].size(); 
        for(int i=0; i<4; i++){
            sum[i] = vector<vector<int>>(n, vector<int>(m, 0));
        }
        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            for(int j=m-1; j>=0; j--)
            {
                if(grid[i][j]){
                    ++cnt;
                }
                else cnt = 0;
                sum[0][i][j] = cnt;//
            }
            cnt = 0;
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]){
                    ++cnt;
                }
                else cnt = 0;
                sum[1][i][j] = cnt;
            }
        }

        for(int j=0; j<m; j++){
            int cnt = 0;
            for(int i=0; i<n; i++)
            {
               
                if(grid[i][j]){
                    ++cnt;
                }
                else cnt = 0;
                sum[2][i][j] = cnt;
            }

            cnt = 0;
            for(int i=n-1; i>=0; i--)
            {
               
                if(grid[i][j]){
                    ++cnt;
                }
                else cnt = 0;
                sum[3][i][j] = cnt;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {

            for(int j=0; j<m; j++)
            {
                int x=min(sum[0][i][j], sum[3][i][j]);
                for(int k = ans+1; k<=x; k++)
                {
                   //if()
                    int y = min(sum[1][i+k-1][j+k-1], sum[2][i+k-1][j+k-1]);
                    if(y >= k) ans = k;
                    //else break;
                }

            }
        }
        return ans*ans;


    }
};