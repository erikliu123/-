
#include<iostream>
#include<vector>
using namespace std;

/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();// col=matrix[0].size();
        for(int i=0; i<n/2; i++)
        {
            for(int j=i; j<n-1-i; j++)//注意边界, 不是j<n-1-i， 因为4*4矩阵最外层也才12个元素，三次即可！
            {
                int tmp = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] =   matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = tmp;
            }
        }

    }
};