#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
/*
题目描述：
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）
现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）


*/
class Solution {
public:

    queue<pair<int, int>> points;//NOTICE: 答案是存0元素对应的点，我存的是第一个岛屿(1)对应的点，所以在ans自增的地方会有出入；当然存0对应的坐标会快一点！
    vector<int> direct={-1,0,1,0,-1};//NOTICE:这是一个技巧，不用二维数组也可以！ direct={1,0,-1,0,1};同意OK
    bool stop=false;
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size() && !stop; ++i)
        {
            for(int j=0; j<grid[i].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    points.push(make_pair(i,j));
                    dfs(points, i, j, grid.size(), grid[0].size(), grid);
                    stop=true;
                    break;
                }
            }

        }
        //BFS
        int ans=0;
        while(!points.empty())
        {
           
            int n=points.size();
            for(int i=0; i<n; i++)
            {
                auto temp=points.front();
                points.pop();
                
                for(int j=0; j<4; j++)
                {
                    pair<int, int> pos{direct[j]+temp.first, direct[j+1]+temp.second};
                    if(pos.second>=0 && pos.first>=0 && pos.first<grid.size() && pos.second<grid[0].size())
                    {
                        if(grid[pos.first][pos.second] == 1)
                        {
                            return ans;
                        }
                        else if(grid[pos.first][pos.second] == 0){
                            grid[pos.first][pos.second] = 2;
                            points.push(pos);
                        }

                    }
                        
                }
            }
             ++ans;
        }
        return 0;

    }

    void dfs(queue<pair<int, int>> &points, int row, int col, int m, int n, vector<vector<int>>& grid)
    {
        for(int i=0; i<4; i++)
        {
            pair<int, int> pos{direct[i], direct[i+1]};
            pos.first+=row;
            pos.second+=col;
            if(pos.second>=0 && pos.first>=0 && pos.first<m && pos.second<n && grid[pos.first][pos.second]==1){
                grid[pos.first][pos.second] = 2;
                points.push(pos);
                dfs(points, pos.first, pos.second, m, n, grid);
            }
        }
    }
};  

int main()
{
    Solution a;
    vector<vector<int>> grid;
    grid.push_back({0,1});
    grid.push_back({1,0});
    int ret=a.shortestBridge(grid);
    return 0;
}