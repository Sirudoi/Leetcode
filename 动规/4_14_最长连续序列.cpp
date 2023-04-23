//128. 最长连续序列
//https://leetcode.cn/problems/longest-consecutive-sequence/submissions/
//求数组最长的连续递增的子序列，不要求元素连续，但是要求连续递增
//动态规划
//dp[i]表示以i结尾的连续序列的最大长度
//nums[i] == nums[i - 1] + 1，则dp[i] = dp[i - 1] + 1
//nums[i] == nums[i - 1]，    则dp[i] = dp[i - 1]
//否则dp[i] = 1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                dp[i] = dp[i - 1];
            else if (nums[i] == nums[i - 1] + 1)
                dp[i] = dp[i - 1] + 1;

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

//压缩DP数组
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int ans = 1;
        int curMaxlen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1)
                curMaxlen += 1;
            if (nums[i] > nums[i - 1] + 1)
                curMaxlen = 1;

            ans = max(ans, curMaxlen);
        }

        return ans;
    }
};

//题目要求O(n)，也就是不能排序
class Solution {
private:
    unordered_set<int> _hashSet;
public:
    int longestConsecutive(vector<int>& nums) {
        for (const int& it : nums) {
            _hashSet.insert(it);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int index = nums[i];
            //nums[i]是递增第一个
            if (!_hashSet.count(index - 1)) {
                int cnt = 1;
                while (_hashSet.count(++index))
                    ++cnt;
                ans = max(ans, cnt);
            }
            
 
        }

        return ans;
    }
};