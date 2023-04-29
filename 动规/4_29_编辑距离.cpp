//72. 编辑距离
//https://leetcode.cn/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]: word1以i结尾变成word2以j结尾需要的最短距离
        //word1[i] == word2[j]: dp[i][j] = dp[i - 1][j - 1]
        //word1[i] != word2[j]: 删除一个字符 || 修改一个字符
        //删除word2[j]: dp[i][j] = dp[i][j - 1] + 1
        //删除word1[i]: dp[i][j] = dp[i - 1][j] + 1
        //修改一个字符: dp[i][j] = dp[i - 1][j - 1] + 1

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        //初始化行
        for (int i = 0; i < dp[0].size(); ++i) {
            dp[0][i] = i;
        }
        //初始化列
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};