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
 //二叉树的直径
 //https://leetcode.cn/problems/diameter-of-binary-tree/submissions/
class Solution {
public:
    int depth(TreeNode* root, int& ans) {
        if (!root) return 0;
        
        //左子树最大深度
        int left = depth(root->left, ans);
        //右子树最大深度
        int right = depth(root->right, ans);

        ans = max(ans, left + right + 1);

        //返回当前节点为根的最长深度
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        depth(root, ans);
        return ans - 1;
    }
};