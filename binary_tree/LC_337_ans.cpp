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
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，
每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    pair<int,int> dfs(TreeNode*root)//一个记录答案，一个记录中间状态
    {
        if(!root) return make_pair(0,0);
        pair<int,int> left_money=dfs(root->left);
        pair<int,int> right_money=dfs(root->right);
        pair<int,int> money;
        money.first =left_money.second+right_money.second+root->val;//加入根节点
        money.second=max(left_money.first,left_money.second)+max(right_money.first,right_money.second);
        //这个容易想错，不选root后，其实子节点也可以不一定要非勾上，所以孩子都有两种情况
        return money;
    }
    int rob(TreeNode* root) {
        pair<int,int> money=dfs(root);
        return max(money.first,money.second);
    }
};