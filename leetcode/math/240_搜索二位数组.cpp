#include<iostream>
#include<vector>
using namespace std;

/*
240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0, col=matrix[0].size()-1;
        while(row<matrix.size() && col>=0)
        {
            //target比较大的时候，row下移; 小的时候, 让col向左移动
            if(matrix[row][col] > target) --col;
            else if(matrix[row][col] < target) ++row;
            else return true;
        }
        return false;
        
    }
};