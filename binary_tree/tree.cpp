//直系节点和三代以内的旁系节点禁止婚配，求给定二叉树两节点是否可以结婚

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
//LC257题：给定一个二叉树，返回所有从根节点到叶子节点的路径。
class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* root, TreeNode *father, string &tmp)
    {
        string str=tmp;
        if(root == NULL){
            return ;
        }
        if(father){
            str+="->"; 
        }
        str+=to_string(root->val);
        
        if(!root->left && !root->right)
        {
            ans.push_back(str);
            return ;
        }
       
        dfs(root->left, root, str);
        dfs(root->right, root, str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp;
        dfs(root, NULL, tmp);
        return ans;
    }
};