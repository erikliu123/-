#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
2003. 每棵子树内缺失的最小基因值
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

#define MAXN 1010
//有问题的版本，不完全对！
class Solution {
    vector<int> e[MAXN], ans;
    bool has1[MAXN], vis[MAXN];
    void dfs_1(int start, vector<int>& nums)
    {
        if(nums[start] == 1)
            has1[start] = true;
        else has1[start] = false;
        for(auto x:e[start])
        {
            dfs_1(x, nums);
            has1[start] |= has1[x];//父亲节点有无1的孩子节点
        }
        if(!has1[start]) 
            ans[start] = 1;
    }
    void dfs_3(int start, vector<int>& nums)
    {
        for(auto x: e[start])
        {
            dfs_3(x, nums);
        }
        vis[nums[start]] = true;
    }
    int now = 1;
    void dfs_2(int start, vector<int>& nums)
    {
        if(!has1[start]) return;
       
        for(auto x: e[start])
        {
            if(has1[x])
                dfs_2(x, nums);//一直找到最底层的1
        }
         //从start开始遍历，找缺失的最小元素
        for(auto x: e[start])
        {
            if(!has1[x])
                dfs_3(x, nums);//遍历所有孩子
        }
        vis[nums[start]] = true;
        while(vis[now])
        {
            ++now;
        }
        ans[start] = now;
    }

public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        ans = vector<int>(n);
        now = 1;
        for (int i = 1; i < parents.size(); i++){//i=0时, parent必定等于-1
            e[parents[i]].push_back(i);//父亲指向儿子
        }
        for(int i=0; i<=parents.size(); i++)
        {
            vis[i] = false;
        }
        dfs_1(0, nums);
        dfs_2(0, nums);

        return ans;

    }
};

int main()
{
    Solution a;
    //vector<int> parent{-1,0,1,0,3,3}, nums{5,4,6,2,1,3};
    vector<int> parent{-1,0,0,1,1,2,2}, nums{6,5,4,1,2,1,3};//NOTICE：测试时不要nums的元素相等，不符合题意
    //vector<int> parent{-1,0,0,2}, nums{1,2,3,4};
    a.smallestMissingValueSubtree(parent, nums);

    return 0;
}