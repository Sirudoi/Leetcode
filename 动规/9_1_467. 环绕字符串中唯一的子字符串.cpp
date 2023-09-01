// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
// 467. 环绕字符串中唯一的子字符串
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        // dp[i]表示，26个字符中，以某一个字符结尾的最多的子字符串的数量
        // 这里不用dp[i]表示以s[i]结尾的数量是因为要去重，比如都是以a结尾，只需要保留最大的即可

        vector<int> dp(26);
        int cur_cnt = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i && (s[i] - s[i - 1] + 26) % 26 == 1) {
                ++cur_cnt;
            }
            else {
                cur_cnt = 1;
            }

            dp[s[i] - 'a'] = std::max(dp[s[i] - 'a'], cur_cnt);
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};