#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/*
329. 矩阵中的最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。

*/
class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};
    vector<vector<int>> child;
    map<pair<int, int>, vector<pair<int, int>>> tuopu;
    map<pair<int, int>, int> dp;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        //visited = 
        child = vector<vector<int>>(n, vector<int>(m, 0));;
        /*记录边*/
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
                        ++child[pos.first][pos.second];
                    }
                    else if(it > matrix[pos.first][pos.second])
                    {
                        tuopu[pos].push_back(make_pair(i,j));
                        ++child[i][j];
                    }
                }
                if(j+1 < m){
                    pos = {i, j+1};
                    if(it < matrix[pos.first][pos.second])
                    {
                        tuopu[make_pair(i,j)].push_back(pos);
                        ++child[pos.first][pos.second];
                    }
                    else if(it > matrix[pos.first][pos.second])
                    {
                        tuopu[pos].push_back(make_pair(i,j));
                        ++child[i][j];
                    }
                }
            }
            
        }
        int ans = 0;
        /* 找到没有父亲的节点，从它为起点开始遍历 */
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(child[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                }

            }
        }
        /* 求BFS能便利到的最深深度 */
        while(!q.empty())
        {
            ans++;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto it = q.front();
                q.pop();
                for(auto x:tuopu[it]){
                    --child[x.first][x.second];
                    if(child[x.first][x.second] == 0)//因为不可能有环路，所以不需要visit数组；但如果题目变成非递减序列，就可能有环路了
                    {
                        q.push(x);
                    }
                }
            }
        }
        return ans;

    }
};