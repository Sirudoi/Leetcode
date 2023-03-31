// Leetcode416 - 分割等和子集
// https://leetcode.cn/problems/partition-equal-subset-sum/submissions/
// 第一次我写的：动态规划，背包问题
// 能分成两个和相等的数组，那么这个和一定是数组全部元素和的一半
// nums数组全部元素和为sum
// 就转化为背包容量sum / 2，商品列表是nums数组，是否存在使得商品价值为sum / 2的情况
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const auto& it : nums)
            sum += it;

        if (sum % 2 != 0) return false;

        sum /= 2;

        // dp[i][j]表示0-i中任取，放入容量为j的背包中，价值最大为多少
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, 0));
        // 初始化行
        for (int i = 0; i <= sum; ++i)
        {
            if (i < nums[0])
                dp[0][i] = 0;
            dp[0][i] = nums[0];
        }
        // 初始化列
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[i][0] = 0;
        }

        // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i])
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 1; j <= sum; ++j)
            {
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);

                if (dp[i][j] == sum) return true;
            }
        }

        return false;
    }
};

// 滚动数组
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum / 2;

        // 一维滚动数组
        vector<int> dp(10001, 0);
        // 初始化一横行
        for (int i = 0; i < dp.size(); ++i)
        {
            if (i >= nums[0])
                dp[i] = nums[0];
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            // dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])
            for (int j = dp.size() - 1; j >= 0; --j)
            {
                if (j < nums[i]) 
                    continue;
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                if (dp[j] == target) return true;
            }
        }

        return false;
    }
};
