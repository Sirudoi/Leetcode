//https://leetcode.cn/problems/minimum-path-sum/submissions/
//64. 最小路径和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < dp.size(); ++j) {
                if (j == 0) dp[j] = dp[j] + grid[i][j];
                else dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[dp.size() - 1];
    }
};