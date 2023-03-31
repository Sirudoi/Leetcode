// leetcode1049 - 最后一块石头的重量Ⅱ
// https://leetcode.cn/problems/last-stone-weight-ii/solution/
// 背包问题
class Solution {
public:
	// 将问题转化为：把石头分成尽量相等的两堆
	// 把两堆相消，得到最小的差值
	// 即在stones里面取若干个石头，尽量使得取到的价值等于sum / 2
	// 此时可以转化成背包问题，容量为sum / 2的背包，取若干个，能取到的最大值
	// 这个是取出一堆，后续做差就可以得到问题的解
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        vector<int> dp(1501, 0);
		// 初始化背包
        for (int i = 0; i < dp.size(); ++i)
        {
            if (i >= stones[0])
                dp[i] = stones[0];
        }

		// 动规计算
        for (int i = 1; i < stones.size(); ++i)
        {
            for (int j = dp.size() - 1; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        // 分成两堆，一堆dp[target]， 另一堆sum - dp[target]
        // sum - dp[target]必定大于等于dp[target]，因为dp[target]容量肯定小于target
        // 返回两堆的差值
        return sum - dp[target] - dp[target];
    }
};