//673. 最长递增子序列的个数
//https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
//最长递增子序列长度的变形题，要先求长度同时累加个数，细节很多，很不好想
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //dp[i]表示：以i结尾的最长子序列长度
        vector<int> dp(nums.size(), 1);
        //cnt[i]表示：以i结尾的最长子序列个数
        vector<int> cnt(nums.size(), 1);
        int maxlen = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            //遍历[0, i - 1]区间，取一个j，使得nums[j] < nums[i]
            //dp[i] = dp[j] + 1，遍历找最大值
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    //j结尾的子序列长度 = i结尾的子序列长度 - 1
                    //例如，[1,3,5,4,7]，以nums[4]的结尾，子序列长度是4
                    //则以nums[4]结尾的子序列个数为：子序列长度是3的和
                    else if (dp[j] + 1 == dp[i])
                    {
                        //累加计算cnt[i]
                        cnt[i] += cnt[j];
                    }
                }
            }
            
            //累加结果，累加每个最长子序列长度为maxlen的个数
            if (dp[i] > maxlen)
            {
                maxlen = dp[i];
                ans = cnt[i];
            }
            else if (dp[i] == maxlen)
                //累加每个最长子序列长度为maxlen的个数
                ans += cnt[i];

        }

        return ans;
    }
};