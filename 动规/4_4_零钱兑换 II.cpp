//Leetcode518 - 零钱兑换Ⅱ
//https://leetcode.cn/problems/coin-change-ii/
//完全背包，组合数，先遍历物品再遍历背包
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = 1; j < dp.size(); ++j)
            {
                if (j >= coins[i])
                    dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};