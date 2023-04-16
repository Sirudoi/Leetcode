//338. 比特位计数
//https://leetcode.cn/problems/counting-bits/

//方法一：直接计算每个数的二进制序列，然后返回
//计算可以用 int __builtin_popcount(unsgined int x) 库函数
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for (int i = 0; i <= n; ++i) {
            ret.emplace_back(__builtin_popcount(i));
        }

        return ret;
    }
};

//动态规划
//如果i为奇数，dp[i] = dp[i - 1] + 1
//如果i为偶数，说明进位了，假设此时i的二进制序列为：xxxxxx0
//则dp[i]为xxxxxx0中前i - 1位的1的数量
//因此dp[i] = dp[i >> 1]
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
			//为基数，直接 + 1
            if (i & 1) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
				//为偶数：假设当前
                dp[i] = dp[i >> 1];
            }
        }

        return dp;
    }
};

