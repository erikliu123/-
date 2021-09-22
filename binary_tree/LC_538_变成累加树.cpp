
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
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
*/
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        //dfs(root, false);
        stack<TreeNode *> st;
        if(!root)
            return nullptr;
        st.push(root);
        TreeNode *tmp = root;
        int sum = 0;
        //反向后序遍历，不可! 我们需要的是反向中序遍历
        // while(tmp || !st.empty())
        // {
        //     while (tmp)
        //     {
        //         st.push(tmp);
        //         tmp = tmp->right;
        //     }
            
        //     auto x = st.top();
        //     sum += x->val;
        //     cout<<sum<<endl;
        //     x->val =sum;
        //     st.pop();
        //     tmp = x->left;
            
        // }
        while(tmp->right)
        {
            st.push(tmp->right);
            tmp = tmp->right;
        }
   
        while(!st.empty())
        {
            
            TreeNode *x = st.top();
            sum += x->val;
            x->val = sum;
            st.pop();
            if(x->left)//要把右边的孩子移动栈的最上面
            {
                tmp = x->left;
                st.push(tmp);
                while(tmp->right)
                {
                    st.push(tmp->right);
                    tmp = tmp->right;
                }
               
            }
            
        }
        return root;
    }
};