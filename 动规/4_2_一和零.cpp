//leetcode474 - 一和零
//https://leetcode.cn/problems/ones-and-zeroes/solution/
//二维数组
class Solution {
public:
    int getOneNum(const string& str)
    {
        int cnt = 0;
        for (auto& c : str)
        {
            if (c == '1') ++cnt;
        }
        return cnt;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp( strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

		//dp[i][j][k]，strs前i个元素任取，0的容量为j，1的容量为k背包最大价值
		//每个元素的价值都是1
        for (int i = 1; i <= strs.size(); i++)
        {
            int oneNum = getOneNum(strs[i - 1]);
            int zeroNum = strs[i - 1].size() - oneNum;
            //0
            for (int j = 0; j <= m; j++)
            {
                //1
                for (int k = 0; k <= n; ++k)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeroNum && k >= oneNum)
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zeroNum][k - oneNum] + 1);
                }
            }
        }

        // for (int i = 0; i <= strs.size(); i++)
        // {
        //     for (int j = 0; j <= m; j++)
        //     {
        //         for (int k = 0; k <= n; ++k)
        //         {
        //             printf("[%d][%d][%d]=[%d] ", i, j, k, dp[i][j][k]);
        //         }
        //         cout << endl;
        //     }
        // }

        return dp[strs.size()][m][n];
    }
};

//滚动数组
class Solution {
public:
    int getOneNum(const string& str)
    {
        int cnt = 0;
        for (auto& c : str)
        {
            if (c == '1') ++cnt;
        }
        return cnt;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < strs.size(); i++)
        {
            int oneNum = getOneNum(strs[i]);
            int zeroNum = strs[i].size() - oneNum;
            //0
            for (int j = m; j >= zeroNum; j--)
            {
                //1
                for (int k = n; k >= oneNum; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - zeroNum][k - oneNum] + 1);
                }
            }
        }

        return dp[m][n];
    }
};