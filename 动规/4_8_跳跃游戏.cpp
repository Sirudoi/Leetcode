//leetcode55. 跳跃游戏
//https://leetcode.cn/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if (nums.size() == 1) return true;

        //dp[i] = i + nums[i];
        //dp[i]表示下标为i的位置是否能被跳跃
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        //记录当前最大跳跃距离
        int len = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            //由i位置跳跃，有更大的跳跃距离
            if (i + nums[i] > len)
            {
                //如果i能跳跃，则[len, i + nums[i]]能被跳跃
                if (dp[i])
                {
                    for (int j = len; j <= i + nums[i]; ++j) 
                        if (j < dp.size()) dp[j] = true;
                        else break;
                }

                //更新跳跃距离
                len = i + nums[i];
            }
        }

        // for (int i = 0; i < dp.size(); ++i)
        // {
        //     cout << "dp[" << i << "]" << "[" << dp[i] << "]" << endl;
        // }

        return dp[nums.size() - 1];
    }
};

//压缩数组，只需要记录最大距离
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //记录当前最大跳跃距离
        int len = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (len >= nums.size() - 1)
                return true;
            
            //最大跳跃距离 = max{当前最大，当前位置跳跃的最大}
            //只有位置i在最大跳跃距离内才更新
            if (len >= i) len = max(len, i + nums[i]);
            //i开始就无法到达，直接跳出
            else break;
        }

        return false;
    }
};