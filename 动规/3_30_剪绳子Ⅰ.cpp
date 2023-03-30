//剑指Offer14 I 捡绳子
//https://leetcode.cn/problems/jian-sheng-zi-lcof/
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        
        vector<int> dp(n + 1, 0);

        dp[2] = 1;
        dp[3] = 2;
        // dp[i]表示长度为i的绳子拆成的最大乘积
        // i拆成j和i-j，如果i-j不能拆了，最大就是j * (i-j)，如果i-j还能拆，最大就是j * dp[i-j]
        // 每次能拆2或者拆3，两个一起比较
        for (int i = 4; i < dp.size(); ++i)
        {
            int max1 = std::max(2 * dp[i - 2], 2 * (i - 2));
            int max2 = std::max(3 * dp[i - 3], 3 * (i - 3));
            dp[i] = std::max(max1, max2); 
        }

        return dp[n];
    }
};