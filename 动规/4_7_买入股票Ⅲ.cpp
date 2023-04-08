//leetcode123. 买卖股票的最佳时机 III
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
//这题比起前面的，就是状态更多了
//第一次我写的，没有看题解
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        //0.第i天未曾持有股票的
        //1.第i天第一次持有股票
        //2.第i天第一次卖出股票
        //3.第i天第二次持有股票
        //4.第i天第二次卖出股票

        //dp[i][0] = dp[i - 1][0]
        //第i天第一次持有股票：前一天持有股票的最大利润，和-prices[i]的最大值
        //dp[i][1] = max{dp[i - 1][1], -prices[i]}

        //第i天第一次卖出股票：max{第i天第一次卖出的最大利润, 前i-1天第一次卖出的最大利润 }
        //dp[i][2] = max{dp[i - 1][2], dp[i - 1][1] + prices[i]}

        //第i天第二次持有股票：前一天卖出股票的最大利润 - prices[i]
        //第三天才能买入，第三天初始化：dp[i][3] = dp[i - 1][2] - prices[i]
        //第四天开始：dp[i][3] = max{前i-1持有的最大值，第i天第二次买入的最大值}

        //第i天第二次卖出股票：max{第i天第二次卖出的最大利润, 前i-1天第二次卖出的最大利润 }
        //dp[i][4] = max{dp[i][2], dp[i - 1][3] + prices[i]}

        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            if (i >= 2) 
            {
                if (i == 2) dp[i][3] = dp[i - 1][2] - prices[i]; //第三天开始，才能买第二次
                else dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            }
            if (i >= 3) dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); //第四天开始，才能卖第二次
        }

        int day = prices.size() - 1;
        return max(dp[day][2], dp[day][4]);
    }
};

//每次只和四个状态有关
//dp[i - 1][1] 前i-1天，第一次持有股票的最大利润
//dp[i - 1][2] 前i-1天，第一次卖出股票的最大利润
//dp[i - 1][3] 前i-1天，第二次持有股票的最大利润
//dp[i - 1][4] 前i-1天，第二次卖出股票的最大利润
//因此可以压缩DP数组
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        //firstOwn.第一次持有股票最大利润
        //fistSell.第一次卖出股票最大利润
        //secondOwn.第二次持有股票最大利润
        //secondSell.第二次卖出股票最大利润

        int firstOwn = -prices[0];
        int firstSell = 0;
        int secondOwn = 0;
        int secondSell = 0;
        
        int _firstOwn = firstOwn;
        int _firstSell = firstSell;
        int _secondOwn = secondOwn;
        int _secondSell = secondSell;

        for (int i = 1; i < prices.size(); ++i)
        {
            _firstOwn = max(firstOwn, -prices[i]);
            _firstSell = max(firstSell, firstOwn + prices[i]);
            if (i >= 2) 
            {
                if (i == 2) _secondOwn = firstSell - prices[i];
                else _secondOwn = max(secondOwn, firstSell - prices[i]);
            }
            if (i >= 3)
                _secondSell = max(secondSell, secondOwn + prices[i]);

            firstOwn = _firstOwn;
            firstSell = _firstSell;
            secondOwn = _secondOwn;
            secondSell = _secondSell;

            // printf("%d %d %d %d\n", firstOwn, firstSell, secondOwn, secondSell);
        }

        return max(firstSell, secondSell);
    }
};

//还能省四个空间，但是貌似没啥用
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        //firstOwn.第一次持有股票最大利润
        //fistSell.第一次卖出股票最大利润
        //secondOwn.第二次持有股票最大利润
        //secondSell.第二次卖出股票最大利润

        int firstOwn = -prices[0];
        int firstSell = 0;
        int secondOwn = -prices[0];
        int secondSell = 0;
        
        // int _firstOwn = firstOwn;
        // int _firstSell = firstSell;
        // int _secondOwn = secondOwn;
        // int _secondSell = secondSell;

        for (int i = 1; i < prices.size(); ++i)
        {
            firstOwn = max(firstOwn, -prices[i]);
            firstSell = max(firstSell, firstOwn + prices[i]);
            secondOwn = max(secondOwn, firstSell - prices[i]);
            secondSell = max(secondSell, secondOwn + prices[i]);
        }

        return secondSell;
    }
};