// https://leetcode.cn/problems/maximum-length-of-pair-chain/submissions/
// 646. 最长数对链

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // 先对pair数组排序
        sort(pairs.begin(), pairs.end());

        vector<int> dp(pairs.size(), 1);
        dp[0] = 1;
        int ans = 1;

        // 按照最长递增子序列的思想, 去获取最大值
        for (int i = 1; i < pairs.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }

            ans = std::max(ans, dp[i]);
        }

        return ans;
    }
};