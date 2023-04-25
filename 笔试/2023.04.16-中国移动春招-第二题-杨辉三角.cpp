//中国移动2023.04.16-春招-第二题-杨辉三角
//http://www.codefun2000.com/p/P1201
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
	vector<vector<int>> _dp;
	int _ans = 0;

	void initDpArray(const int& n)
	{
		_dp.resize(n + 1);
		for (int i = 1; i < n + 1; ++i)
		{
			_dp[i].resize(i + 1);
			//第i行第1个和第i个都是奇数
			_dp[i][1] = _dp[i][i] = 1;
			//从i行第2个开始递推
			for (int j = 2; j < i; ++j)
			{
				//递推第i行第j个数是否是奇数
				_dp[i][j] = _dp[i - 1][j] ^ _dp[i - 1][j - 1];
			}
		}
	}

public:
	int getAnster(const int& n)
	{
		initDpArray(n);
		int row = _dp.size() - 1;
		for (int i = 0; i < _dp[row].size(); i++)
		{
			if (_dp[row][i])
				++_ans;
		}
		return _ans;
	}
};

int main()
{
	Solution sl;
	int n;
	cin >> n;
	cout << sl.getAnster(n) << endl;
}