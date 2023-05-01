//剑指 Offer 47. 礼物的最大价值
//https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
//二维dp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));

		//dp[i][j]: 取第i行j列的物品，能获得最大价值
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[row][col];
    }
};

//滚动数组压缩
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int length = grid[0].size();
        vector<int> dp(length + 1);

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 1; j <= length; ++j) {
                dp[j] = max(dp[j], dp[j - 1]) + grid[i][j - 1];
            }
        }

        return dp[length];
    }
};