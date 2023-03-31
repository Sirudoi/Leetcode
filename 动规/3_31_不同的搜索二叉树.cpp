//leetcode 96 不同的搜索二叉树
//https://leetcode.cn/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        // dp[n]表示n个节点能构成多少种不同的搜索树
        // 以n = 3举例，所有种类的树就是：以1为根节点的搜索树，以2为根节点的搜索树，以3为根节点的搜索树
        // 以 1 为根节点：左子树节点个数为0，右子树节点个数为2。则以1为根节点一共有：dp[0] * dp[2]
        // 以 2 为根节点：左子树节点个数为1，右子树节点个数为1。则以2为根节点一共有：dp[1] * dp[1]
        // 以 3 为根节点：左子树节点个数为2，右子树节点个数为0。则以3为根节点一共有：dp[2] * dp[0]

        // 所以dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0]

        // 外层计算dp[i]
        for (int i = 2; i < n + 1; ++i)
        {
            // 内层计算以 j 为根节点的搜索树数量
            for (int j = 1; j <= i; ++j)
            {
                // 对于j为根节点有
                // 左：dp[j - 1] 右：dp[i - j]
                // 总数：dp[j - 1] * dp[i - j]
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};