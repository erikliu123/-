
/*
98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

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
//NOTICE：此题要注意, 对于每个子节点，满足a[left] < a[mid] <a[right]，但是仍然未必是搜索二叉树！！
/*
    5
  3    6
      4  7 
*/
class Solution {
public:
    vector<int> record;
    void dfs(TreeNode* root)
    {
        if(!root) return ;
        dfs(root->left);
        record.push_back(root->val);
         dfs(root->right);

    }
    bool isValidBST(TreeNode* root) {
        record.clear();
        dfs(root);
        
        for(int i=1; i<record.size(); i++)
        {
            //cout<<record[i]
            if(record[i] <= record[i-1]) return false;
        }
        return true;
        // if(!root) return true;
        // bool flag1=true, flag2=true;
        // if(root->left){
        //     flag1 = (root->left->val < root->val);
        // }
        // if(root->right){
        //     flag2 = (root->right->val > root->val);
        // }
        // if(!flag1 || !flag2) 
        //     return false;

        // return isValidBST(root->left) && isValidBST(root->right);


    }
};