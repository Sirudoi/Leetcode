//https://codefun2000.com/p/P1259
//华为od第一题，单词倒序
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
	// 分割字符串，将分割结果整合到数组
	void splitString(const char token = ' ')
	{
		size_t begin = 0;
		size_t index = _in.find(token, begin);
		size_t length = index - begin;

		while (begin < _in.size() && index != std::string::npos)
		{
			_wordVector.emplace_back(_in.substr(begin, length));
			begin = index + 1;
			index = _in.find(token, begin);
			length = index - begin;
		}
		_wordVector.emplace_back(_in.substr(begin, length));
	}

	std::string getReverseAnswer()
	{
		getline(cin, _in);

		splitString();

		std::string ans;
		for (int i = 0; i < _wordVector.size(); ++i)
		{
			// 获取最后一个字符
			int index = _wordVector[i].size() - 1;
			// 排除结尾有特殊字符的情况，保证逆序的都是单词，即reverse的部分必须全是字母
			while (index >= 0 && !isalpha(_wordVector[i][index]))
			{
				index--;
			}
			// 反转单词
			reverse(_wordVector[i].begin(), _wordVector[i].begin() + index + 1);

			ans += _wordVector[i];
			// 控制最后一个空格不要添加
			if (i < _wordVector.size() - 1) ans += ' ';
		}

		return ans;
	}

protected:
	std::string _in;
	std::vector<std::string> _wordVector;
};

int main()
{
	cout << Solution().getReverseAnswer() << endl;

	return 0;
}