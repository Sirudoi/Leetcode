//剑指Offer33 - 二叉搜索树的后序遍历序列
//https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
//给你一个遍历序列，返回这个序列是否是一个二叉搜索树的后序遍历序列
//一、递归
//[1,3,2,6,5] 最后一个数是根节点：5
//左子树的数都比 5 小，右子树的数都比 5 大
//左子树：[1,3,2] 右子树[6]
//递归检查左右子树数是否合法
class Solution {
public:
    bool _verifyPostorder(vector<int>& postorder, int left, int right)
    {
        if (left >= right)
            return true;
        int root = postorder[right];
        int index = left;
        // 找到比root大节点，则index左边是左子树，右边是右子树
        // 注意边界控制index <= right - 1，[left, right - 1]找比root大的节点
        while (index <= right - 1 && postorder[index] < root)
        {
            ++index;
        }
        // 分完左右子树后，检查右子树所有数值是否合法
        // 注意边界，检查[index, right - 1]所有数是否合法
        for (int i = index; i <= right - 1; ++i)
        {
            if (postorder[i] < root)
                return false;
        }

        // 递归检查左右子树[left, index - 1][index, right - 1]
        return _verifyPostorder(postorder, left, index - 1) &&
               _verifyPostorder(postorder, index, right - 1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        return _verifyPostorder(postorder, 0, postorder.size() - 1);
    }
};