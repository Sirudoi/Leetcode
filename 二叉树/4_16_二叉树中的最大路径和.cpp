//124. 二叉树中的最大路径和
//https://leetcode.cn/problems/binary-tree-maximum-path-sum/
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
    //记录最大值
    int ans = INT_MIN;
public:
    int PostOrder(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val;
        }

        int bothPass, onePass, noPass;
        //右单支为空
        if (root->left && !root->right) {
            int leftMax = PostOrder(root->left);

            //(经过root && 最多一个单支) -> max{root，左孩子+root}
            onePass = max(root->val, leftMax + root->val);
            //(经过root && 两个单支) -> 和onePass相同
            bothPass = onePass;
            //不经过root -> 左孩子
            noPass = leftMax;
        }
        //左单支为空
        else if (!root->left && root->right) {
            int rightMax = PostOrder(root->right);

            //(经过root && 最多一个单支) -> max{root，右孩子+root}
            onePass = max(root->val, rightMax + root->val);
            //(经过root && 两个单支) -> 和onePass相同
            bothPass = onePass;
            //不经过root -> 右孩子
            noPass = rightMax;
        }
        //左右都不为空
        else {
            int leftMax = PostOrder(root->left);
            int rightMax = PostOrder(root->right);

            //(经过root && 最多一个单支) -> max{右孩子+root, 左孩子+root, root}
            onePass = max(max(leftMax + root->val, rightMax + root->val), root->val);
            //(经过root && 两个单支) -> {左孩子 + 右孩子 + 根}
            bothPass = leftMax + rightMax + root->val;
            //不经过root -> max{左孩子, 右孩子}
            noPass = max(leftMax, rightMax);
        }
        
        // cout << "经过:" << root->val << " onePass:" << onePass << " bothPass" << bothPass << " noPass" << noPass << endl;

        //ans = max(继续向上走，不继续向上走)
        //继续向上走：  (经过root && 最多一个单支)
        //不继续向上走：(不经过root) || (经过root && 经过两个单支)
        ans = max(ans, max(onePass, max(noPass, bothPass)));

        //返回(经过root && 最多一个单支)
        return onePass;
    }

    int maxPathSum(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val;
        }

        PostOrder(root);
        return ans;
    }
};