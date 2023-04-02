//leetcode494 - 目标和
//https://leetcode.cn/problems/target-sum/
//二维数组
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //假设组成target的目标表达式，加法总和为x，则减法总和为sum - x
        //所以target = x - (sum - x) -> x = (sum + target) / 2
        //问题转化为装满容量为x的背包，有几种方法
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int x = (sum + target) / 2;
        //x = (sum - target) / 2，如果sum - target不是偶数，那么此时加法总和为小数
        //又因为nums数组都是整数，所以满足条件的方法直接为0，没有解
        if (abs(target) > sum || (sum + target) % 2 != 0) return 0;

        //dp[i][j]表示数组的前i个任取，能装满背包容量为j的方法
        //不取第i个数：dp[i][j] = dp[i - 1][j]
        //  取第i个数：dp[i][j] = dp[i - 1][j - nums[i]]
        //如果j < nums[i]：dp[i][j] = dp[i - 1][j]
        //如果j >= nums[i]：dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]]
        vector<vector<int>> dp(nums.size() + 1, vector(x + 1, 0));
        // 0个元素任取，使得和为0，初始化成1
        dp[0][0] = 1;

        // 从i = 1开始走，注意这里的边界控制，i = 1代表的是nums[i - 1]
        for (int i = 1; i <= nums.size(); ++i)
        {
            for (int j = 0; j <= x; ++j)
            {
                if (j < nums[i - 1]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }
        }

        
        // for (int i = 0; i <= nums.size(); ++i)
        // {
        //     for (int j = 0; j <= x; ++j)
        //     {
        //         printf("[%d][%d]=[%d] ", i, j, dp[i][j]);
        //     }
        //     cout << endl;
        // }

        return dp[nums.size()][x];
    }
};

//滚动数组，跟着二维来压缩
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        int x = (sum + target) / 2;
        if ((sum + target) & 1) return 0;

        // dp[i]表示容量大小为i的背包，装满有几种方法
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = x; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[x];
    }
};

//回溯
class Solution {
public:
    void backtrack(vector<int>& nums, const int& x, int sum, int index)
    {
        // sum == x不能return，可能后面有0
        if (sum >= x)
        {
            if (sum == x) ++cnt;
            // 大于直接return
            else return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            sum += nums[i];
            backtrack(nums, x, sum, i + 1);
            sum -= nums[i];
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum || (sum + target) & 1) return 0;
        int x = (sum + target) / 2;

        //回溯寻找，有几种方案和为x
        backtrack(nums, x, 0, 0);

        return cnt;
    }
private:
    int cnt = 0;
};