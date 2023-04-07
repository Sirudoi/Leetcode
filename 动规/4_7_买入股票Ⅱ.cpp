//122. 买卖股票的最佳时机 II
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
//二维数组
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        //dp[i][0]：第i天不持有股票的最大利润，取决于max{昨天不持有，昨天持有今天卖了}
        //dp[i][1]：第i天持有股票的最大利润，取决于max{昨天持有，昨天不持有今天买了}
        //dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + price[i])
        //dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - price[i]) 这里是减
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        // for (int i = 0; i < prices.size(); ++i)
        // {
        //     printf("[%d][0]:[%d] [%d][1]:[%d]\n", i, dp[i][0], i, dp[i][1]);
        // }

        return dp[prices.size() - 1][0];
    }
};

//压缩DP数组
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        
        //dp[i][0]：第i天不持有股票的最大利润，取决于max{昨天不持有，昨天持有今天卖了}
        //dp[i][1]：第i天持有股票的最大利润，取决于max{昨天持有，昨天不持有今天买了}
        //dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + price[i])
        //dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - price[i])

        // dp[0][0] = 0;
        // dp[0][1] = -prices[0];

        // for (int i = 1; i < prices.size(); ++i)
        // {
        //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        //     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        // }

        //后续状态只和dp[i - 1][0]和dp[i - 1][1]有关，因此可以压缩DP数组
        int dp0 = 0;          //dp[0]
        int dp1 = -prices[0]; //dp[1]

        for (int i = 1; i < prices.size(); ++i)
        {
            int tmp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, dp0 - prices[i]);
            dp0 = tmp0;
        }

        return dp0;
    }
};