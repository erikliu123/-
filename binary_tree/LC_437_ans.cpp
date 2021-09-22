
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
     int pathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        return calPathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);//计算
    }
    int calPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        int tmp = 0;
        sum -= root->val;
        if (sum == 0) {
            tmp++;
        }
        return tmp + calPathSum(root->left, sum) + calPathSum(root->right, sum);
    }
};