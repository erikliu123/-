#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
二维数组只有0和1两个值，0代表不是炸弹，1代表炸弹。炸单爆炸时该炸弹所在格子和以该炸弹为中心周围的8个格子都属于爆炸区域，同时也会导致周围8个格子中的炸弹也发生爆炸，每个格子的边长为1。
现给定坐标对该坐标的炸弹进行引爆，如果该坐标没有炸弹则不会引爆周围的炸弹，请通过编程的方式计算爆炸区域的周长。
1、二维数据最大256*256
2、任意爆炸波及的边都统计到结果
3、周长只统计二维数组内的格子，以外的不算爆炸区域
*/
class Solution {
public:
    vector<vector<bool>> visited;
    int ans = 0;
    vector<int> direction{-1,0,1,0,-1,1,1,-1,-1};
    bool valid_pos(int row,int col,vector<vector<int>> &grid)
    {
        if( row<0 || col<0 || row>=grid.size() || col >= grid[0].size())
        {
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>> &arr, int startX, int startY)
    {
        if(!arr[startX][startY])
        {
            return ;
        }

        for(int i=0; i<8; i++)
        {
            int nextX = startX + direction[i], nextY = startY + direction[i+1];
            if(valid_pos(nextX, nextY, arr) && !visited[nextX][nextY])
            {
                ++ans;
                visited[nextX][nextY] = true;
                dfs(arr, nextX, nextY);
            }

        }
    }
    int explode_range(vector<vector<int>> &arr, int startX, int startY) {
        visited = vector<vector<bool>>(arr.size(), vector<bool>(arr[0].size(), false));
         dfs(arr, startX, startY);
         return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> vec
    {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1},

    };
    a.explode_range(vec, 0 , 0);
    return 0;
}

