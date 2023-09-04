// 376. 摆动序列
// https://leetcode.cn/problems/wiggle-subsequence/description/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return n;

        vector<int> f(n);   // 以i结尾, 最长的最后一次是递增的子序列
        vector<int> g(n);   // 以j结尾, 最长的最后一次是递减的子序列
        f[0] = g[0] = 1;

        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            for (int j = 0; j < i; ++j) {
				// 找j结尾, 到j位置是递减的最长子序列
                if (diff > 0) {
                    f[i] = std::max(f[i], g[j] + 1);
                    g[i] = 1;
                }
				// 找j结尾, 到j位置是递增的最长子序列
                else if (diff < 0) {
                    g[i] = std::max(g[i], f[j] + 1);
                    f[i] = 1;
                }
                else {
                    f[i] = g[i] = 1;
                }
            }

            ans = std::max(std::max(f[i], g[i]), ans);
        }

        return ans;
    }
};

// 滚动数组
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return n;

        int up = 1;     // 最后一项是递增的最长子序列长度
        int down = 1;   // 最后一项是递减的最长子序列长度

        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i - 1];
            // 找递减的最长子序列
            if (diff > 0) {
                up = down + 1;
            }
            // 找递增的最长子序列
            else if (diff < 0) {
                down = up + 1;
            }
        }

        return std::max(up, down);
    }
};