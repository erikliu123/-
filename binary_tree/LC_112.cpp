
/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。

叶子节点 是指没有子节点的节点。

*/
class Solution {
public:
    bool dfs(TreeNode* root, int targetSum, int cursum)
    {
        if(root==NULL){
            return false;
        }
        if(root->left == NULL && root->right ==NULL){
            return cursum + root->val == targetSum;
        }
        else
        return dfs(root->left, targetSum, root->val+cursum) ||  dfs(root->right, targetSum, root->val+cursum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);


    }
};