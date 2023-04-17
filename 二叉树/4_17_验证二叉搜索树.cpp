//验证二叉搜索树
//https://leetcode.cn/problems/validate-binary-search-tree/submissions/
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

//方法一：中序遍历
//二叉搜索树中序遍历一定是有序的，中序遍历，如果中途有一个数违反有序的规则直接返回假
class Solution {
private:
    vector<int> _path;
    bool _flag = true;
public:
    void _isValidBST(TreeNode* root) {
        if (!root) return;

        _isValidBST(root->left);
        if (!_path.empty()) {
            if (_path.back() < root->val)
                _path.emplace_back(root->val);
            else {
                _flag = false;
                return;
            }
        }
        else _path.emplace_back(root->val);
        _isValidBST(root->right);
    }

    bool isValidBST(TreeNode* root) {
        _isValidBST(root);
        return _flag;
    }
};

//节约空间的中序
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

//只用一个值记录前一个值的大小
//每次比较这个节点大小就好了
class Solution {
private:
    long _preVal = LONG_MIN;
    bool _flag = true;
public:
    void _isValidBST(TreeNode* root) {
        if (!root)
            return;
        
        _isValidBST(root->left);
        if (root->val <= _preVal) {
            _flag = false;
            return;
        }
        _preVal = root->val;
        _isValidBST(root->right);
    }

    bool isValidBST(TreeNode* root) {
        _isValidBST(root);
        return _flag;
    }
};