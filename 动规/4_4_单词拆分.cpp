//leetcode139. 单词拆分
//https://leetcode.cn/problems/word-break/
//完全背包，有顺序要求，排列
//这是我写的
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;

        unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 0; j < wordDict.size(); ++j)
            {
                int sz = wordDict[j].size();
                if (i >= sz)
                {
                    //i往前切分sz个字符，如果[i-sz, i]可以被分割
                    if (hashSet.count(s.substr(i - sz, sz)))
                        dp[i] = 1;

                    //检查[0,i-sz]能否被分割，如果[0,i-sz]可以分割，则整体[0，i]可以被分割
                    dp[i] = dp[i] & dp[i - sz];
                    //检测到可以分割直接break，不然再往后走会影响，因为wordDict里面字符的长度不是有序的
                    if (dp[i]) break;
                }
            }
        }

        // for (int i = 0; i < dp.size(); ++i)
        // {
        //     printf("[%d]=[%d]\n", i, dp[i]);
        // }

        return dp[s.size()];
    }
};

//可以简化判断条件，但是这样其实多切割了很多次
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
        for (int i = 1; i < dp.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                //切分[j, i]的字符串
                //[j, i]可以分割 && [0, j]可以分割，则整体可以分割
                if (hashSet.count(s.substr(j, i - j)) && dp[j])
                    dp[i] = true;
            }
        }

        return dp[s.size()];
    }


};