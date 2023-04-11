//674. 最长连续递增序列
//https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
//dp数组
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //dp[i],以i元素结尾的最长连续子序列长度
        //nums[i - 1] < nums[i], dp[i] = dp[i - 1] + 1
        //nums[i - 1] >= nums[i], dp[i] = 1;

        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] < nums[i])
                dp[i] = dp[i - 1] + 1;
            if (dp[i] > res) res = dp[i];
        }

        return res;
    }
};

//压缩dp数组
//dp[i]的状态只和dp[i - 1]有关
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //dp[i],以i元素结尾的最长连续子序列长度
        //nums[i - 1] < nums[i], dp[i] = dp[i - 1] + 1
        //nums[i - 1] >= nums[i], dp[i] = 1;

        int res = 1;
        int lastLen = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] < nums[i])
                lastLen += 1;
            else lastLen = 1;
            if (lastLen > res) res = lastLen;
        }

        return res;
    }
};