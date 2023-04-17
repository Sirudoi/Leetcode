//105. 从前序与中序遍历序列构造二叉树
//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
private:
    unordered_map<int, int> _inMap;
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,
        int pLeft, int pRight, int iLeft, int iRight) {
            if (pLeft > pRight || iLeft > iRight)
                return nullptr;
            
            if (pLeft == pRight)
                return new TreeNode(preorder[pLeft]);

            TreeNode* root = new TreeNode(preorder[pLeft]);

            //根节点在中序遍历的位置
            int rootIndex = _inMap[preorder[pLeft]];
            //左子树长度
            int length = rootIndex- iLeft;

            //[       左       ]   根   [     右         ] -> 中序遍历
            //[ileft, index - 1, index, index + 1, iright]
            //  根   [         左             ] [          右             ] -> 前序遍历
            //[root, pleft + 1, pleft + length, pleft + length + 1, pright]

            //递归构建左右子树
            root->left = _buildTree(preorder, inorder, pLeft + 1, pLeft + length, iLeft, rootIndex - 1);
            root->right = _buildTree(preorder, inorder, pLeft + length + 1, pRight, rootIndex + 1, iRight);

            return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            _inMap[inorder[i]] = i;
        }

        return _buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};