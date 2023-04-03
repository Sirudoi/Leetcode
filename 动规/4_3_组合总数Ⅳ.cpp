//组合总数Ⅳ
//https://leetcode.cn/problems/combination-sum-iv/
//记忆化回溯，直接回溯会超时
class Solution {
public:
    int backtrack(vector<int>& nums, int target)
    {
        if (target == 0) return 1;
        if (target < 0) return 0;
		// 如果target计算过，则直接返回其值
        if (mem.count(target) > 0) return mem[target];

		// 否则计算target目标有多少种方法
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += backtrack(nums, target - nums[i]);
        }
        mem[target] = sum;

        return sum;
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if (nums[0] > target) return 0;
        backtrack(nums, target);

        return mem[target];
    }
private:
    // mem[i]表示目标数为i有多少种方法
    unordered_map<int, int> mem;
};