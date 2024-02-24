/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 两次遍历，分别获取p q节点的路径，根据路径找祖先 */
class Solution {
public:
    std::vector<TreeNode*> p_path_;
    std::vector<TreeNode*> q_path_;

public:
    /* 获取target节点的路径 */
    void getOneTreeNodePath(TreeNode* root, TreeNode* target, std::vector<TreeNode*>& path) {
        path.emplace_back(root);

        if (target->val == root->val) {
            return;
        }
        else if (target->val > root->val) {
            getOneTreeNodePath(root->right, target, path);
        }
        else {
            getOneTreeNodePath(root->left, target, path);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getOneTreeNodePath(root, p, p_path_);
        getOneTreeNodePath(root, q, q_path_);

        TreeNode* ansNode = nullptr;
        /* 第一个不相同节点上一个节点就是最近公共祖先 */
        for (int i = 0; i < p_path_.size() && i < q_path_.size(); ++i) {
            if (p_path_[i] == q_path_[i]) {
                // printf("p_path_[i]:%08x q_path_[i]:%08x\n", p_path_[i], q_path_[i]);
                ansNode = p_path_[i];
            }
            else break;
        }

        return ansNode;
    }
};

/* 一次遍历 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* 当p q节点分别在root左右两边，root节点就是最近公共祖先 */
        int larger = std::max(p->val, q->val);
        int smaller = std::min(p->val, q->val);
        TreeNode* target = root;

        while (true) {
            if (root->val > larger) {
                /* 公共祖先还在左边 */
                root = root->left;
            }
            else if (root->val < smaller) {
                /* 公共祖先还在右边 */
                root = root->right;
            }
            else {
                /* 当前节点即为所求 */
                target = root;
                break;
            } 
        }

        return target;
    }
};