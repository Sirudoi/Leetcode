//152. 乘积最大子数组
//https://leetcode.cn/problems/maximum-product-subarray/

//需要考虑复述 * 负数等于正数的情况，因此需要存储最小值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //dp[i][0]:以i结尾的连续子数组最大乘积
        //dp[i][1]:以i结尾的连续子数组最小乘积
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        //nums[i] >= 0: dp[i][0] = max(dp[i - 1][0] * nums[i], nums[i])
        //              dp[i][1] = min(dp[i - 1][1] * nums[i], nums[i])
        //nums[i] < 0 : dp[i][0] = max(dp[i - 1][1] * nums[i], nums[i])
		//              dp[i][1] = min(dp[i - 1][0] * nums[i], nums[i])

        int ans;
        ans = dp[0][1] = dp[0][0] = nums[0];
        for (int i = 1; i < dp.size(); ++i) {
            if (nums[i] >= 0) {
                dp[i][0] = max(dp[i - 1][0] * nums[i], nums[i]);
                dp[i][1] = min(dp[i - 1][1] * nums[i], nums[i]);
            }
            else {
                dp[i][0] = max(dp[i - 1][1] * nums[i], nums[i]);
                dp[i][1] = min(dp[i - 1][0] * nums[i], nums[i]);
            }
            ans = max(dp[i][0], ans);
        }

        return ans;
    }
};

//压缩DP
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //DP方程只和上一次的最小值和最大值有关，可以压缩
        int ans, preMax, preMin;
        ans = preMax = preMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                preMax = max(preMax * nums[i], nums[i]);
                preMin = min(preMin * nums[i], nums[i]);
            }
            else {
                int tmp = preMax;
                preMax = max(preMin * nums[i], nums[i]);
                preMin = min(tmp * nums[i], nums[i]);
            }
            ans = max(ans, preMax);
        }

        return ans;
    }
};