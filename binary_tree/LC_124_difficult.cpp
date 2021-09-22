#include <iostream>
#include <map>
using namespace std;

/*
124. 二叉树中的最大路径和

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。
该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode *, int> sum;
    map<TreeNode *, bool> mark;
    int ans;
    int recursive(TreeNode* root)
    {
        if(!root)
            return 0;
        int ret = root->val;
        int xx = recursive(root->left);
        int yy = recursive(root->right);
        if(root->left && mark[root->left]){
            xx-=min(sum[root->left->right], sum[root->left->left]);
            ans = max(ans, xx);
            sum[root->left] = xx;
        }
        if(root->right && mark[root->right]){
            yy-=min(sum[root->right->right], sum[root->right->left]);
            ans = max(ans, yy);
            sum[root->right] = yy;
        }

        sum[root] = max(ret, max(ret+xx, max(ret+yy, ret+xx+yy)));
        if(sum[root] == ret + xx +yy && root->left && root->right)
        {
            mark[root] = true;
            
        }
        ans = max(ans, sum[root]);
        return  sum[root];
    }
    // int recursive2(TreeNode* root)
    // {
    //     if(!root)
    //         return 0;
    //     int ret = sum[root] - 
    //     //int ret = root->val + recursive(root->left) + recursive(root->right);
    //     //sum[root] = ret;
    //     return ret;
    // }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
         recursive(root);
        for(auto x: sum)
        {
            if(ans < x.second)
            {
                ans = x.second;
            }

        }
        return ans;

    }
};
