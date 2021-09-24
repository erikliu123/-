#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
有一棵根节点为 0 的 家族树 ，总共包含 n 个节点，节点编号为 0 到 n - 1 。给你一个下标从 0 开始的整数数组 parents ，
其中 parents[i] 是节点 i 的父节点。由于节点 0 是 根 ，所以 parents[0] == -1 。

总共有 105 个基因值，每个基因值都用 闭区间 [1, 105] 中的一个整数表示。给你一个下标从 0 开始的整数数组 nums ，
其中 nums[i] 是节点 i 的基因值，且基因值 互不相同 。

请你返回一个数组 ans ，长度为 n ，其中 ans[i] 是以节点 i 为根的子树内 缺失 的 最小 基因值。
节点 x 为根的 子树 包含节点 x 和它所有的 后代 节点。

提示：
n == parents.length == nums.length
2 <= n <= 105
对于 i != 0 ，满足 0 <= parents[i] <= n - 1
parents[0] == -1
parents 表示一棵合法的树。
1 <= nums[i] <= 10^5
nums[i] 互不相同。（NOTICE: 关键点！）
*/

//NOTICE: 此方法会超时，如果题目nums[i]允许相同，需要用此解法
class Solution {
public:
    unordered_map<int, vector<int>> edges;
    vector<bool> visited;
    vector<int> ans;
    void dfs(vector<int>& parents, vector<int>& nums, int root,  vector<bool> &visited)
    {
        if(root < 0)
            return ;

        if(edges.count(root))
        {
            for(auto x:edges[root])
            {
                vector<bool> tmp;
                tmp = vector<bool>(nums.size()+1, false);
                dfs(parents, nums, x, tmp);
            
                for(int i = 0; i<tmp.size(); i++)
                    visited[i] = visited[i] || tmp[i];//归并子问题的解
            }
            
        }
        if(nums[root] <= visited.size())
            visited[nums[root]] = true;
            
             
        bool overflow = true;
        for(int i=1; i<visited.size(); i++)
        {
            if(!visited[i])
            {
                ans[root] = i;
                overflow = false;
                break;
            }
        }
        if(overflow)
            ans[root] = visited.size();   
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int index = 0;
        int root = 0;
        ans = vector<int>(nums.size(), 1);
        for(auto x: parents)
        {
            if(x > -1)
                edges[x].push_back(index);
            else{
                root = index;
            }
            index++;
        }
        visited = vector<bool>(nums.size()+1, false);
        dfs(parents, nums, root, visited);
        return ans;

    }
};

int main()
{
    Solution a;
    //vector<int> parent{-1,0,1,0,3,3}, nums{5,4,6,2,1,3};
    vector<int> parent{-1,0,0,1,1,2,2}, nums{6,5,4,1,2,1,3};
    parent =  vector<int>{-1,0,0,1,1,2,2,3};
    nums= vector<int>{4,4,1,1,2,3,2,3};
    //vector<int> parent{-1,0,0,2}, nums{1,2,3,4};
    a.smallestMissingValueSubtree(parent, nums);

    return 0;
}