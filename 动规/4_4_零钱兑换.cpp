//322. 零钱兑换
//https://leetcode.cn/problems/coin-change/
//完全背包，等于求背包装满的最小价值，变形题目
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = 1; j < dp.size(); ++j)
            {
                if (j >= coins[i])
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        if (dp[amount] == INT_MAX - 1)
            return -1;
        else return dp[amount];
    }
};