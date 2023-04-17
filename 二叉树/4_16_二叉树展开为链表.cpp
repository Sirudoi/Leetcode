//114. 二叉树展开为链表
//https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
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
    void _flatten(TreeNode* root) {
        if (!root) return;

        //递归处理左右子树
        _flatten(root->left);
        _flatten(root->right);

        TreeNode* right = root->right;
        TreeNode* leftTail = root->left;
        
        //左子树添加到root的右孩子，左子树为空直接跳过
        if (leftTail) {
            root->right = leftTail;
            //根节点左边置空
            root->left = nullptr;

            //找左子树右孩子的叶子节点
            while (leftTail->right) {
                leftTail = leftTail->right;
            }
            //把右子树插入到左子树树尾的右节点
            leftTail->right = right;
        }
    }

    void flatten(TreeNode* root) {
        _flatten(root);
    }
};