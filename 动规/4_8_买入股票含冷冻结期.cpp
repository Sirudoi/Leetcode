//309. 最佳买卖股票时机含冷冻期
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//强状态的递推DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        //0买入
        //1卖出
        //2冷冻
        //dp[i][j]表示前i天，状态为j时的最大利润
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = -prices[0];

        //dp[i][j] = max{前i天状态j的最大值，第i天刚进入状态j的值}
        //dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i])
        //dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        //dp[i][2] = max(dp[i - 1][2], dp[i - 1][1])

        //外层控制第i天，从第二天开始递归
        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        int day = prices.size() - 1;
        return max(dp[day][1], dp[day][2]);
    }
};

//滚动数组
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        
        int buy = -prices[0];
        int sell = 0;
        int frozen = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            int _sell = sell;
            //i - 1天卖出的最大值，第i天卖出的值
            sell = max(sell, buy + prices[i]);
            //i - 1天买入的最大值，第i天买入的值
            buy = max(buy, frozen - prices[i]);
            //i - 1天冻结期，第i天进入冻结期
            frozen = max(frozen, _sell);

            //这里需要定义_sell存储sell，因为第i天进入冻结期：值是i - 1天卖出
            //上面已经把卖出的值更新成第i天了
            //所以这里需要调整更新顺序
        }

        return max(frozen, sell);
    }
};
