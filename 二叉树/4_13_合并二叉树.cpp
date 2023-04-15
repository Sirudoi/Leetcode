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
 //617. 合并二叉树
 //https://leetcode.cn/problems/merge-two-binary-trees/
class Solution {
public:
    TreeNode* _mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            root1->val += root2->val;
            root1->left = _mergeTrees(root1->left, root2->left);
            root1->right = _mergeTrees(root1->right, root2->right);
            return root1;
        }
        else if (root1 && !root2) {
            root1->left = _mergeTrees(root1->left, nullptr);
            root1->right = _mergeTrees(root1->right, nullptr);
            return root1;
        }
        else if (!root1 && root2) {
            root2->left = _mergeTrees(nullptr, root2->left);
            root2->right = _mergeTrees(nullptr, root2->right);

            return root2;
        }
        else return nullptr;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)
            return root2;
        if (!root2)
            return root1;

        _mergeTrees(root1, root2);
        return root1;
    }
};