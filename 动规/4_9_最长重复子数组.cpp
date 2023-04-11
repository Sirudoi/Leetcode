//718. 最长重复子数组
//https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]表示nums1以i为起点, nums2以j为起点，的最大公共子数组的和
        //nums1[i] == nums2[j], 则dp[i][j] = dp[i + 1][j + 1] + 1
        //nums1[i] != nums2[j], 则dp[i][j] = 0

        int ans = 0;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector<vector<int>> dp(sz1, vector<int>(sz2, 0));

        //由于dp[i][j]由dp[i + 1][j + 1]状态递推而来
        //因此这里需要逆序遍历，先求dp[i + 1][j + 1]的状态
        if (nums1[sz1 - 1] == nums2[sz2 - 1])
            dp[sz1 - 1][sz2 - 1] = 1;

        for (int i = sz1 - 1; i > -1; --i)
        {
            for (int j = sz2 - 1; j > - 1; --j)
            {
                if (nums1[i] == nums2[j])
                {
                    if (i < sz1 - 1 && j < sz2 - 1)
                        dp[i][j] = dp[i + 1][j + 1] + 1;
                    else dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }

        // for (int i = 0; i < sz1; ++i)
        // {
        //     for (int j = 0; j < sz2; ++j)
        //     {
        //         printf("[%d][%d]:[%d] ", i, j, dp[i][j]);
        //     }
        //     cout << endl;
        // }

        return ans;
    }
};