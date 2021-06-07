#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/*
130. 被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
*/
class Solution {
public:
    queue<pair<int, int>> q;
    vector<int> direct{{-1,0,1,0,-1}};
    vector<vector<bool>> visit;
    bool dfs(pair<int, int> pos, vector<vector<char>>& board)
    {
        if(pos.first<0 || pos.second<0 || pos.first>=board.size() || pos.second>=board[0].size())
        {
            return false;
        }
        if(board[pos.first][pos.second] != 'O')
        {
            return true;
        }
        if(visit[pos.first][pos.second]){
            return true;
        }
        visit[pos.first][pos.second] = true;
        if(board[pos.first][pos.second] == 'O')
        {
            q.push(pos);
        }
        int ret = true;
        for(int i=0; i<4; i++){
             pair<int, int> next{pos.first + direct[i], pos.second + direct[i+1]};
            bool temp=dfs(next, board);
            ret = ret && temp;
            
        }
        return ret;
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> tmp;
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == 'O') {
                    visit = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
                    bool change = dfs(make_pair(i,j), board);
                    tmp = q;
                    // bool change = true;
                    // //遍历queue中所有元素看是否能越界
                    // while(!q.empty())
                    // {
                    //     auto pos=q.front();
                    //     q.pop();
                    //     for(int i=0; i<4; i++){
                    //         pair<int, int> next{pos.first + direct[i], pos.second + direct[i+1]};
                    //         if(next.first<0 || next.second<0 || next.first>=board.size() || next.second>=board[0].size())
                    //         {
                    //             change = false;
                    //             break;
                    //         }
                    //     }
                        
                    // }
                     while(!q.empty())  q.pop();
                    
                    while(!tmp.empty()){
                        auto pos=tmp.front();
                        if(change)
                            board[pos.first][pos.second] = 'X';
                        else
                            board[pos.first][pos.second] = 'W';
                        tmp.pop();
                    }
                   
                }
            }
        }

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == 'W')
                    board[i][j] = 'O';
            }
        }

    }
};

int main()
{
    Solution a;
    vector<vector<char>> grid{{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    //grid.push_back(vector<char>{'X','O','X','X'});
    //  grid.push_back(vector<char>{'X','O','X','X'});
    a.solve(grid);
    return 0;
}
