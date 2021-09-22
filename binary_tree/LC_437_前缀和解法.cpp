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
/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
*/
class Solution {
public:
    int ans = 0;
    unordered_map<int, int> hashMap;
    void dfs(TreeNode* root, int targetSum, int curSum)
    {
        if(!root)
            return ;
        
        curSum += root->val;
        if(hashMap.count(curSum - targetSum))
        {
            ans += hashMap[curSum - targetSum];
        }
        hashMap[curSum]++;
        dfs(root->left, targetSum, curSum);
        dfs(root->right, targetSum, curSum);


        hashMap[curSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        hashMap[0] = 1;
        dfs(root, targetSum, 0);
        return ans;

    }
};