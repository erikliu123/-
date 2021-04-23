#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ans;
    void DFS(int start_row, int start_col, int row_len, int col_len,  vector<vector<char>>& matrix, vector<vector<int>> &col, vector<vector<int>> &row)
    {
        //横向扩张
        int area=row_len*col_len;
        if(matrix.size()==0||matrix[0].size()==0) return ;
        if(start_row+row_len > matrix.size() || col_len+start_col > matrix[0].size()) return;
        int last_row=start_row+row_len-1, last_col=col_len+start_col-1;
        for(int i=0; last_col+i<matrix[0].size(); i++)
        {
            if(row[last_row+1][last_col+i+1] - row[start_row][last_col+i+1]==col_len){
                ans=max(ans, area);
                area += col_len;
                DFS(start_row,  start_col, row_len, col_len+i+1, matrix, col, row);
            }
            else{
                if(matrix[start_row][last_col+i])
                    DFS(start_row, last_col+i, 1, 1, matrix, col, row);//找下一个
                break;
            }
        }

        //纵向扩张
          area=row_len*col_len;
        for(int i=0; last_row+i<matrix.size(); i++)
        {
            if(col[last_row+i+1][last_col+1] - col[last_row+i+1][start_col]==row_len){
                ans=max(ans, area);
                area += row_len;
                DFS(start_row,  start_col, row_len+i+1, col_len, matrix, col, row);
            }
            else{
                if(matrix[last_row+i][start_col])
                    DFS(last_row+i, start_col, 1, 1, matrix, col, row);
                //DFS(last_row+i, start_col+1, 1, 1, matrix, col, row);//往右
                break;
            }
        }

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> col_one_cnt(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        vector<vector<int>> row_one_cnt(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j])
                {
                    col_one_cnt[i+1][j+1]= col_one_cnt[i][j+1]+1;
                    row_one_cnt[i+1][j+1]= row_one_cnt[i+1][j]+1;
                }
                else{
                    col_one_cnt[i+1][j+1]= col_one_cnt[i][j+1];
                    row_one_cnt[i+1][j+1]= row_one_cnt[i+1][j];
                }

            }
        }
        ans=0;
        DFS(0,0,1,1,matrix, col_one_cnt, row_one_cnt);
        return ans;

    }
};

int main()
{
    Solution a;
    vector<vector<char>> matrix;
    matrix.push_back({1,1,1,1,0});
    matrix.push_back({1,0,1,1,0});
    matrix.push_back({1,0,1,1,0});
    int ans=a.maximalRectangle(matrix);//为什么结果是12，9
    cout<<ans<<endl;
    return 0;
}