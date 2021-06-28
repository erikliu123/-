#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
   
    queue<pair<int, int>> pos;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ans = mat;
        int depth=0;
        vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
        vector<int> direct{-1,0,1,0,-1};
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j] == 0){
                    pos.push(make_pair(i,j));
                    visit[i][j]=true;
                }
            }
        }
        while(!pos.empty())
        {
            int n = pos.size();
            for(int i=0; i<n; i++)
            {
                pair<int, int> point = pos.front();
                pos.pop();
                ans[point.first][point.second] = depth;
                for(int k=0; k<4; k++)
                {
                     pair<int, int> next{point.first + direct[k], point.second + direct[k+1]};
                     if(next.first < 0 || next.second <0 || next.first>=mat.size() || next.second>=mat[0].size()) continue;
                     if(!visit[next.first][next.second]){
                         visit[next.first][next.second] = true;
                         pos.push(next);
                     }
                }
            }
            ++depth;
        }
        return ans;


    }
};