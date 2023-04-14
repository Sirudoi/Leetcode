//leetcode单词拆分 II
//https://leetcode.cn/problems/word-break-ii/
class Solution {
private:
    //以key为起点的字符串，可以拆分的句字
    unordered_map<int, vector<string>> _ans;
    unordered_set<string> _dictMap;

public:
    vector<string>& backTracking(string& s, int index)
    {
        //记录存在，直接返回
        if (_ans.count(index))
            return _ans[index];

        //第一次走到结尾，返回
        if (index == s.size())
        {
            _ans[index] = { "" };
            return _ans[index];
        }

        _ans[index] = {};
        for (int i = index + 1; i <= s.size(); ++i)
        {
            string word = s.substr(index, i - index);
            //[index, i]能被切分
            if (_dictMap.count(word))
            {
                //继续分割[i + 1, 结尾]
                backTracking(s, i);

                //遍历插入i位置记忆的所有结果
                for (const auto& it : _ans[i])
                {
                    //这里可以分割前插入word，但是后续需要构建word和后续结果的拼接
                    //先插入word不好处理
                    if (it.empty())
                        _ans[index].emplace_back(word);
                    else _ans[index].emplace_back(word + " " + it);
                }
            }
        }

        return _ans[index];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        _dictMap = unordered_set<string>(wordDict.begin(), wordDict.end());
        backTracking(s, 0);

        return _ans[0];
    }
};