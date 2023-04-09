//714. 买卖股票的最佳时机含手续费
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//多一个手续费，没啥区别本质上，多减一个fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            int _buy = buy;
            buy = max(buy, sell - prices[i]);
            sell = max(sell, _buy + prices[i] - fee);
        }

        return sell;
    }
};