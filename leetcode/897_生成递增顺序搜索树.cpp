
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
    TreeNode* increasingBST(TreeNode* root) {//[2,1,4,null,null,3] 
        stack<TreeNode*> s;
        bool set_root=false;
        TreeNode* r=root, *prev=NULL;
        while(!s.empty() || root)
        {
            while(root){
                s.push(root);
                root=root->left;
            }
            //找到最左边的了
            TreeNode* tmp=s.top();
            if(!set_root){
                set_root=true;
                r=tmp;
            }
            else{
                prev->left=NULL;
                prev->right=tmp;
            }
            prev=tmp;
            root=tmp->right;
            s.pop();

        }
        if(prev)
            prev->left=prev->right=NULL;//NOTICE：尾部处理很重要，对于[2,1,4,null,null,3] 尾部节点是4.需要将原来的left子节点也要设置NULL
        return r;

    }
};