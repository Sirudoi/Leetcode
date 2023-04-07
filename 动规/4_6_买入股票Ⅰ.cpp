//121. 买卖股票的最佳时机
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
//递推DP
//执行用时超过18%
//内存消耗超过25%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][j]表示前i天任取一天买，第j天卖的最大价值
        // dp[i][j] = max(dp[i - 1][j], prices[j] - prices[i])

        // 把二维的压缩成一维的
        vector<int> dp(prices.size(), 0);
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
			//第j天卖，j从i + 1开始递推，并且要保证prices[j] > prices[i]
            for (int j = i + 1; j < prices.size() && prices[j] > prices[i]; j++)
                dp[i] = std::max(dp[i], prices[j] - prices[i]);
            
            if (dp[i] > ans)
                ans = dp[i];
        }

        // for (int i = 0; i < dp.size(); ++i)
        // {
        //     printf("[%d]:[%d]\n", i, dp[i]);
        // }

        return ans;
    }
};

//好像还能继续压缩，只存储上次的最大值
//执行用时超过19%
//内存消耗超过40%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][j]表示前i天任取一天买，第j天卖的最大价值
        // dp[i][j] = max(dp[i - 1][j], prices[j] - prices[i])

        // 继续压缩
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size() && prices[j] > prices[i]; j++)
                ans = std::max(ans, prices[j] - prices[i]);
        }

        return ans;
    }
};

//优化成一次遍历
//总体思想就是需要记录前i - 1天的最小买入价值
//执行用时超过89.39%
//内存消耗62.78%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0; // 前i天的最大收益
        int minValue = INT_MAX; //前i天最小买入售价
        for (int i = 0; i < prices.size(); i++)
        {
            minValue = min(minValue, prices[i]);
			// 最大收益 = 前i - 1天的最大收益，第i天卖出价格 - 前i天最小买入价格
            ans = max(ans, prices[i] - minValue);
        }

        return ans;
    }
};