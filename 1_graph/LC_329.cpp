#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
329. 矩阵中的最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

*/
class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};
    vector<vector<bool>> child;
    map<pair<int, int>, vector<pair<int, int>>> tuopu;
    map<pair<int, int>, int> dp;
    int dfs(pair<int, int> start)
    {
        int ans = 0;
        if(dp.count(start))//避免重复DFS，记录每个结点的最大深度很重要
            return dp[start];
        //if(tuopu)
        for(auto x: tuopu[start])
        {
            int temp = dfs(x);
            ans = max(temp, ans);

        }
        dp[start] = 1+ans;
        return 1+ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();
        child = vector<vector<bool>>(n, vector<bool>(m, false));;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                auto it = matrix[i][j];
                pair<int, int> pos = {i+1, j};

                if(i+1 < n){
                    
                    if(it < matrix[pos.first][pos.second])
                    {
                        tuopu[make_pair(i,j)].push_back(pos);
                        child[pos.first][pos.second] = true;
                    }
                    else if(it > matrix[pos.first][pos.second])
                    {
                        tuopu[pos].push_back(make_pair(i,j));
                        child[i][j] = true;
                    }
                }
                if(j+1 < m){
                    pos = {i, j+1};
                    if(it < matrix[pos.first][pos.second])
                    {
                        tuopu[make_pair(i,j)].push_back(pos);
                        child[pos.first][pos.second] = true;
                    }
                    else if(it > matrix[pos.first][pos.second])
                    {
                        tuopu[pos].push_back(make_pair(i,j));
                        child[i][j] = true;
                    }
                }
              
            }
            
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(child[i][j] == false)
                {
                    int maxdepth = dfs(make_pair(i, j));
                    //cout<<maxdepth<<endl;
                    if(ans < maxdepth)
                        ans = maxdepth;
                }

            }
        }
        return ans;

    }
};