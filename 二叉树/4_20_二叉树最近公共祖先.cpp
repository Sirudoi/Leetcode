//二叉树最近公共祖先
//剑指 Offer 68 - II. 二叉树的最近公共祖先
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* ans = nullptr;
public:
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;

		//当前节点左节点是否有p或q
        bool lTree = dfs(root->left, p, q);
		//当前节点右节点是否有p或q
        bool rTree = dfs(root->right, p, q);

        //p,q分别在左右 || root是p(q)其中一个，且q(p)在其中一个子树
        //那么当前节点就是所求
        if ( (lTree && rTree) || ((lTree || rTree) && (root == p || root == q)) )
            ans = root;

		//向上返回
        return lTree || rTree || (root == p || root == q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, q, p);

        return ans;
    }
};