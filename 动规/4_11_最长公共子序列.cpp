//1143. 最长公共子序列
//https://leetcode.cn/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        //dp[i][j]表示以text1范围为：[0, i-1]， text2范围为：[0, j-1]的最长公共子序列长度
        //text1[i] == text2[j], dp[i][j] = dp[i - 1][j - 1] + 1
        //text1[i] != text2[j], dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

        for (int i = 1; i <= text1.size(); ++i)
        {
            for (int j = 1; j <= text2.size(); ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        // for (int i = 0; i <= text1.size(); ++i)
        // {
        //     for (int j = 0; j <= text2.size(); ++j)
        //     {
        //         printf("[%d][%d]:[%d]  ", i, j, dp[i][j]);
        //     }
        //     cout << endl;
        // }

        return dp[text1.size()][text2.size()];
    }
};