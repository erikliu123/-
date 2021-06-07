#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
/*
题目描述：
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row=0, col=0;
        if(matrix.size() == 0 ||matrix[0].size()==0) return 0;
        vector<vector<int>> cnt(matrix.size()+2, vector<int>(matrix[0].size(), -1));
        for(auto &i: matrix)
        {
            col=0;
            int temp=0;
            for(auto &j: i)
            {
                if(j=='1'){
                    temp++;
                }
                else {
                    temp=0;
                }
                cnt[row+1][col]=temp;
                //cout<< cnt[row+1][col] <<" ";
                col++;
            }
            //cout<<endl;
            row++;
        }
        /*类似最大矩阵问题*/
        int ans=0;
        for(int i=0; i<col; i++)
        {
            stack<int> s;
            s.push(0);
            for(int r=1; r<=row+1; r++)
            {
                if(cnt[r][i] >= cnt[s.top()][i]){
                    ;//s.push(r);
                }
                else{
                    
                    while(!s.empty() && cnt[r][i] < cnt[s.top()][i]){
                        int height=cnt[s.top()][i];
                        s.pop();
                        if(!s.empty())
                            ans=max(ans, height*(r-s.top()-1));
                    }
                    // if(!s.empty())
                    // ans=max(ans, height*(r-s.top()-1));
                }
                s.push(r);
            }

        }
        return ans;

    }
};