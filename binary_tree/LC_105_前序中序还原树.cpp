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
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
/*
    1 2 3 
    3 2 1
*/
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preorderedIntervalStart, int len,
        int inorderedIntervalStart)
    {
        if(len<=0)
            return NULL;
        int x = preorder[preorderedIntervalStart];
        TreeNode* newItem = new TreeNode(preorder[preorderedIntervalStart]);
        if(len == 1)
            return newItem;
        
        int left = preorder[preorderedIntervalStart+1];
        //在inorder里面找到左孩子
        int leftIndex, fatherIndex ;
        for(int i=inorderedIntervalStart; i<inorderedIntervalStart+len; i++)
        {
            if(inorder[i] == left)
            {
                leftIndex = i;
            }
            if(inorder[i] == x)
            {
                fatherIndex = i;
            }

        }
        int leftChildLen = fatherIndex - inorderedIntervalStart;
        // if(curlen < 0)
        // {
        //     curlen = 0;
        // }
        newItem->left = build(preorder, inorder, preorderedIntervalStart + 1, leftChildLen, inorderedIntervalStart);
        newItem->right = build(preorder, inorder, preorderedIntervalStart +1 + leftChildLen, len - leftChildLen - 1, fatherIndex+1);
        // }
        // else
        //     newItem->right = build(preorder, inorder, startLeft+1, inorder.size()-(startLeft+1+curlen), true);

        return newItem;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return  build(preorder, inorder, 0, preorder.size(), 0);
    }
};