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
 
// 337. 打家劫舍 III
// https://leetcode.cn/problems/house-robber-iii/
// 树形递推DP，要了解好树的遍历方式，结合递推公式
class Solution {
public:
    // 返回值有两个：
    // 1. 当前节点为入口，能偷到的最大值
    // 2. 不以当前节点为入口，能偷到的最大值。这个值就等于其左孩子节点能偷的最大值 + 右孩子节点能偷的最大值
    // 返回{max(当前节点), max(当前节点->left) + max(当前节点->right)}
    std::pair<int, int> PostOrder(TreeNode* root)
    {
        // 空节点返回0 0
        if (!root) return make_pair(0, 0);

        // 后序遍历，保证从叶子节点到根
        pair<int, int> left = PostOrder(root->left);
        pair<int, int> right = PostOrder(root->right);
        //不取当前节点，则最大金额为：max(左孩子节点) + max(右孩子节点)
        //取当前节点，则最大金额为： 当前节点值 + max(不取左孩子节点) + max(不取右孩子节点)
        
        //不取当前节点，最大金额为：max(左孩子节点) + max(右孩子节点)
        int value1 = left.first + right.first;
        //取当前节点，最大金额为：当前节点值 + 左孩子节点的(max(左孩子节点) + max(右孩子节点)) + 右孩子节点的(max(左孩子节点) + max(右孩子节点))
        int value2 = root->val + left.second + right.second;

        //返回{max(当前节点), max(当前节点->left) + max(当前节点->right)}
        return make_pair(max(value1, value2), left.first + right.first);
    }

    int rob(TreeNode* root) {
         pair<int, int> ans = PostOrder(root);

        return ans.first;
    }
};