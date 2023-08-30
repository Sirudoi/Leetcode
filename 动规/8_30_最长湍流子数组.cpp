// https://leetcode.cn/problems/longest-turbulent-subarray/description/
// 978. 最长湍流子数组

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // dp[i]: 以i结尾的最长湍流子数组
		// 情况一：
        // arr[i - 2] > arr[i - 1] < arr[i]
        // arr[i - 2] < arr[i - 1] > arr[i]
        // dp[i] = dp[i - 1] + 1
		// 情况二：
		// 不符合上面的情况，但是arr[i - 1] != arr[i]
		// dp[i] = 2
		// 情况三：
		// arr[i - 1] == arr[i]
		// dp[i] = 1
        if (arr.size() == 1) return 1;

        vector<int> dp(arr.size());
        dp[0] = 1;
        dp[1] = (arr[0] == arr[1] ? 1 : 2);
        int ans = std::max(dp[0], dp[1]);

        for (int i = 2; i < arr.size(); ++i) {
            if ((arr[i - 2] > arr[i - 1] && arr[i - 1] < arr[i]) ||
                (arr[i - 2] < arr[i - 1] && arr[i - 1] > arr[i])) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                if (arr[i - 1] != arr[i]) {
                    dp[i] = 2;
                }
                else {
                    dp[i] = 1;
                }
            }
            // std::cout << dp[i] << std::endl;
            ans = std::max(ans, dp[i]);
        }

        return ans;
    }
};