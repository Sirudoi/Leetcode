//198. 打家劫舍
//https://leetcode.cn/problems/house-robber/
//递推DP，没啥好说的，这题不是背包，最近做魔怔了
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2)
            return nums[0];
        
        int bagSize = nums.size();
        //第i个取：dp[i] = dp[i - 2] + values[i]
        //不取:dp[i] = dp[i - 1]
        vector<int> dp(bagSize + 1, 0);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i <= nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        // for (int i = 0; i <= bagSize; ++i)
        // {
        //     printf("[%d]:[%d]\n", i, dp[i]);
        // }

        return dp[bagSize];
    }
};

//上面我自己写的，开多一个空间，下面这个简洁点
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2)
            return nums[0];
        
		//dp[i]表示，前i个方间能偷的最大价值
        vector<int> dp(nums.size(), 0);
		
        dp[0] = nums[0];               //只有一个方间，偷一个
        dp[1] = max(nums[0], nums[1]); //只有两个方间，选最大的偷

        for (int i = 2; i < nums.size(); ++i)
        {
			//第i个方间偷：dp[i] = dp[i - 2] + nums[i]
			//第i个方间不偷：dp[i] = dp[i - 1]
			//dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};