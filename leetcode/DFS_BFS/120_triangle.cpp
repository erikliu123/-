#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
/*
给定一个三角形 triangle ，找出自顶向下的最小路径和。
每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

示例 1：
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/

/*
测试结果：
执行用时：4 ms, 在所有 C++ 提交中击败了93.64%的用户
内存消耗：8.6 MB, 在所有 C++ 提交中击败了5.28%的用户
*/
//NOTICE：优点类似于二叉树问题，但又不完全等同，因为一个孩子可以有两个父亲。。
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> visited;
    int min_dfs(vector<vector<int>>& triangle, int level, int index)
    {
        int n=triangle.size();
        int ret;
        if(visited[level][index]) 
            return dp[level][index];
        if(level == n-1){
            ret = triangle[level][index];
        }
        //int ret = triangle[level][index];
        else
         ret = triangle[level][index] + min(min_dfs(triangle, level+1, index), min_dfs(triangle, level+1, index+1));
        dp[level][index] = ret;
        visited[level][index] = true;

        return ret;
        

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp = triangle;
        for(int i=0; i<triangle.size(); i++){
            visited.push_back(vector<bool>(i+1, false));
        }
        
        if(triangle.size() == 1) return triangle[0][0];
        return min_dfs(triangle, 0, 0);



    }
};