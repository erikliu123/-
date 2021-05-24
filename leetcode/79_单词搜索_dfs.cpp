#include<iostream>
#include<vector>
using namespace std;
/*
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

*/
class Solution {
public:
    bool ret;
    vector<vector<bool>> visit;
    bool valid(vector<vector<char>>& board, int row, int col, char target)
    {
        if(row<0 || col <0 || row>=board.size() || col>=board[0].size())
        {
            return false;
        }
        return board[row][col] == target && !visit[row][col];

    }
    void dfs(vector<vector<char>>& board,  int begin, int row, int col, string &target)
    {
        
        if(begin == target.size())
        {
            ret = true;
        }
        if(ret) return ;
        if(row<0 || col <0 || row>=board.size() || col>=board[0].size())
        {
            return ;
        }
        if(begin == 0){
            for(int i=0; i<board.size(); i++)
            {
                for(int j=0; j<board[i].size(); j++)
                {
                    if( !visit[i][j]  && target[begin] == board[i][j]){
                        visit[i][j] = true;
                        dfs(board, begin+1, i, j, target);
                        visit[i][j] = false;
                    }

                }

            }
        }
        else{
            if(valid(board, row, col+1, target[begin]) ){
                visit[row][col+1] = true;
                 dfs(board, begin+1, row, col+1, target);
                visit[row][col+1] = false;
            }
            if(valid(board, row, col-1, target[begin])){
                visit[row][col-1] = true;
                dfs(board, begin+1, row, col-1, target);
                visit[row][col-1] = false;
            }
            if(valid(board, row+1, col, target[begin])){
                visit[row+1][col] = true;
                 dfs(board, begin+1, row+1, col, target);
                visit[row+1][col] = false;
            }
            if(valid(board, row-1, col, target[begin])){
                visit[row-1][col] = true;
                 dfs(board, begin+1, row-1, col, target);
                visit[row-1][col] = false;
            }


        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        ret = false;
        visit=vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        dfs(board, 0, 0, 0, word);
        return ret;
    }
};

/*NOTICE: 学习答案的写法，比较简洁！*/
class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
