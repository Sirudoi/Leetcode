//32. 最长有效括号
//https://leetcode.cn/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0 || s.size() == 1) 
            return 0;

        //dp[i]:以下标i结尾的序列，最长有效括=-09
        //1. s[i] == ')' && s[i - 1] == '(' 
        //此时有: dp[i] = dp[i - 2] + 2
        //2. s[i] == '('                    
        //此时有: dp[i] = dp[i - 1]
        //3. s[i] == ')' && s[i - dp[i - 1] - 1] == ')'
        //此时有: dp[i] = dp[i - 1]
        //4. s[i] == ')' && s[i - dp[i - 1] - 1] == '('
        //此时有: dp[i] = dp[i - dp[i - 1] - 1] + 2;

        int ans = 0;
        vector<int> dp(s.size() + 1, 0);

        //dp[2]开始递推，s[1]开始递推
        //dp[i]表示s中以i - 1下标结尾的，注意一下这点
        for (int i = 2; i <= s.size(); i++) {
            if (s[i - 1] == ')') {
                //.....()
                if (s[i - 2] == '(') {
                    dp[i] = dp[i - 2] + 2;
                }
                //.....))
                else {
                    //找对称
                    //...((...|...))对称过去是(, dp[i] = dp[对称位置 - 1] + 长度(i - 对称位置)
                    //...)(...|...))对称过去式), dp[i] = 0;
                    //对称位置: i - 1位置 - 以i - 1位置结尾的最长长度
                    int index = i - dp[i - 1] - 2;
                    if (index >= 0 && s[index] == '(') {
                        //dp[i] = dp[对称位置 - 1] + 长度(i - index)
                        //对称位置 - 1就是dp[index]，因为我这里递推公式 + 1
                        dp[i] = dp[index] + i - index;
                    }
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};