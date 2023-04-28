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
//剑指 Offer 34. 二叉树中和为某一值的路径
//https://leetcode.cn/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
class Solution {
private:
    vector<int> _path;
    vector<vector<int>> _ans;
public:
    void dfs(TreeNode* root, const int& target) {
        if (!root)
            return;
        _path.emplace_back(root->val);
        int sum = accumulate(_path.begin(), _path.end(), 0);
        if (sum >= target) {
            if (sum == target && !root->left && !root->right)
                _ans.emplace_back(_path);
        }

        dfs(root->left, target);
        dfs(root->right, target);
        _path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);

        return _ans;
    }
};