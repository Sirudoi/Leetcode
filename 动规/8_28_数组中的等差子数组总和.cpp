// https://leetcode.cn/problems/arithmetic-slices/submissions/
// 413. 等差数列划分
// 时间: 4ms, 超过46%
// 空间: 6.97MB, 超过41%
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return 0;

        // dp[i]:以i结尾的数，有多少个等差数列
        // dp[i] dp[i - 1] dp[i - 2]等差,   dp[i] = dp[i - 1] + 1
        // dp[i] dp[i - 1] dp[i - 2]不等差, dp[i] = 0 
        vector<int> dp(n);
        int ans = 0;

        for (int i = 2; i < n; ++i) {
            int d1 = nums[i - 1] - nums[i - 2];
            int d2 = nums[i] - nums[i - 1];
            if (d1 == d2) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                continue;
            }
            ans += dp[i];
        }

        return ans;
    }
};

// 优化成滚动数组
// 时间: 0ms, 超过100%
// 空间: 6.97MB, 超过58.97%
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return 0;

        int ans = 0;
        int preOne = 0;
        int preTwo = 0;
        for (int i = 2; i < n; ++i) {
            int d1 = nums[i - 1] - nums[i - 2];
            int d2 = nums[i] - nums[i - 1];
            if (d1 == d2) {
                preTwo = preOne;
                preOne += 1;
            }
            else {
                preTwo = preOne;
                preOne = 0;
            }
            ans += preOne;
        }

        return ans;
    }
};