
/*
124. 二叉树中的最大路径和
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。
该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

提示：
树中节点数目范围是 [1, 3 * 10^4]
-1000 <= Node.val <= 1000
*/
class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sumLeft = maxGain(node->left);
        int sumRight = maxGain(node->right);
        //选取左边, 或者右边
        if(sumLeft < 0) sumLeft = 0;
        if(sumRight < 0) sumRight = 0;

        //int maximum = max(sumLeft, sumRight) + node->val;
        int twoChildSum = (sumLeft + sumRight) + node->val;
        maxSum = max(maxSum, twoChildSum);

        //maxSum = max(node->val + max(sumLeft, sumRight), maxSum);
        return node->val + max(sumLeft, sumRight);//这里只能返回一边的最大值！ 不可以 (sumLeft + sumRight) + node->val, 因为会有重复
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
