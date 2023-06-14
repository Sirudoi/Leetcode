// https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/submissions/
// 剑指 Offer 48. 最长不含重复字符的子字符串
// 这题没写出来，多看几次
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> memory;
        int right = 0, ans = 0;

        // 遍历, 把每一个字符当作起点, 开始滑动, 起点位置就是左指针的位置
        for (int i = 0; i < s.size(); ++i) {
            
            // 每次重新开始, 即左指针位置改变, 删除前一个
            // |abcde -> a|bcde -> ab|cde
            if (i != 0) {
                // 一开始不删, i = 1开始删除i - 1位置
                memory.erase(s[i - 1]);
            }

            // 开始滑动
            while (right < s.size() && memory.count(s[right]) != 1) {
                // 当前不存在, 向右滑动, 右指针++
                memory.insert(s[right]);
                ++right;
            }
            // 遇到重复, 左指针++, 更新ans
            ans = max(ans, right - i);
            // cout << "right - i = " << right << " - " << i << endl;
        }

        return ans;
    }
};