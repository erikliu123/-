
/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

*/
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
    int ans = 0;
    void single_node(TreeNode* root, int targetSum)
    {
        if(!root) return ;
        if(root->val == targetSum)
        {
            ans++;
        }
        single_node(root->left, targetSum);
        single_node(root->right, targetSum);

    }
    void dfs(TreeNode* root, int targetSum, int curSum, bool isFirst)
    {
        //加入root
        if(!root) return ;
        if(isFirst)//第一个
        {
            ;
        }
        else {

            if(curSum + root->val == targetSum )//和之前的累加
            {
                cout<<root->val<<endl;
                ans++;
            }
        }
        curSum += root->val;
        dfs(root->left, targetSum, curSum, false);
        dfs(root->left, targetSum, 0, true);
        dfs(root->right,targetSum, curSum, false);
        dfs(root->right, targetSum, 0, true);
 

    }
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        single_node(root, targetSum);
        dfs(root, targetSum, 0, true);
        return ans;

    }
};
