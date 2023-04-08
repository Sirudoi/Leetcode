class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 1) return 0;
        
        vector<int> own(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);

        // 前i天
        for (int i = 1; i < prices.size(); ++i)
        {
            for (int j = 1; j <= k; j++)
            {
                // 第j次持有：max{前一天j-1次持有的最大利润, 当天买入的最大利润}
                // 当天买入最大利润 = 前一天j-1次不持有 - 当天的价格
                // 这里数组复用，i - 1天
                own[j] = max(own[j], sell[j - 1] - prices[i]);

                // 第j次不持有 = max{i - 1天j-1次不持有的最大利润， 第i天卖的最大利润}
                // 第i天卖的最大利润 = i - 1天j-1持有 + 第i天价格
                sell[j] = max(sell[j], own[j] + prices[i]);
            }
        }

        // for (int i = 0; i <= k; i++)
        // {
        //     printf("own[%d]:%d sell[%d]:%d\n", i, own[i], i, sell[i]);
        // }

        return sell[k];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 1) return 0;
        
        vector<int> own(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);

        // 前i天
        for (int i = 1; i < prices.size(); ++i)
        {
            for (int j = 1; j <= k; j++)
            {
                // 第j交易：max{当前交易, 当天买入}
                // 当天买入 = j - 1卖出 - 当天的价格
                own[j] = max(own[j], sell[j - 1] - prices[i]);

                // 第j售卖 = max{当前售卖， 当天卖出}
                // 当天卖出 = j次买入 + 第i天价格
                sell[j] = max(sell[j], own[j] + prices[i]);
            }
        }

        // for (int i = 0; i <= k; i++)
        // {
        //     printf("own[%d]:%d sell[%d]:%d\n", i, own[i], i, sell[i]);
        // }

        return sell[k];
    }
};