//279. 完全平方数
//https://leetcode.cn/problems/perfect-squares/
//完全背包，装满背包的最小价值，好像有数学解法
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i)
        {
            int power = i * i;
            for (int j = 1; j < dp.size(); ++j)
            {
                if (j >= power && dp[j - power] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - power] + 1);
            }
        }

        return dp[n];
    }
};