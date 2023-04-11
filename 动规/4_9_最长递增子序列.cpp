//leetcode300. 最长递增子序列
//https://leetcode.cn/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       //dp[i]以i结尾的最递增子序列的长度
       //dp[i] = max(dp[i], dp[j] + 1)
       //dp[j]表示nums[j] < nums[i]，即比第i个数小的子序列 + 1
        vector<int> dp(nums.size(), 1);
        int ans = 1;
       for (int i = 0; i < nums.size(); ++i)
       {
           for (int j = 0; j < i; ++j)
           {
               //遍历全部符合nums[j] < nums[i]
               //取最大值
                if (nums[j] < nums[i]) 
                    dp[i] = max(dp[i], dp[j] + 1);
                if (ans < dp[i])
                    ans = dp[i];
           }
       } 

       return ans;
    }
};