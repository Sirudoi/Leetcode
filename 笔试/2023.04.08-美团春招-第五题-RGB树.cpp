//美团2023.04.08-春招-第五题-RGB树
//http://www.codefun2000.com/p/P1170
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
private:
	//存储树的结构，_tree[i]表示第i个节点有多少个节点和它相连（包含父节点）
	vector<vector<int>> _tree;
	//存储颜色，_color[i]表示第i个节点的颜色
	vector<char> _color;
	//dp[i][0]:以第i个节点为根R颜色节点数目
	//dp[i][1]:以第i个节点为根G颜色节点数目
	//dp[i][2]:以第i个节点为根B颜色节点数目
	vector<vector<int>> _dp;
	//R颜色总数
	int _totalR = 0;
	//G颜色总数
	int _totalG = 0;
	//B颜色总数
	int _totalB = 0;
	//答案
	int _ans = 0;

public:
	//处理IO
	void getIO()
	{
		int n;
		cin >> n;

		_tree = vector<vector<int>>(n + 1);
		_color = vector<char>(n + 1);
		_dp = vector<vector<int>>(n + 1, vector<int>(3, 0));

		for (int i = 2; i <= n; ++i)
		{
			int node;
			cin >> node;
			//i节点和node相连
			_tree[i].push_back(node);
			//node节点和i相连
			_tree[node].push_back(i);
		}

		for (int i = 1; i <= n; ++i)
		{
			//输入颜色
			char c;
			cin >> c;
			_color[i] = c;
		}
	}

	void dfsColorSum(int child, int parent)
	{
		//记录当前节点的颜色
		if (_color[child] == 'R')
		{
			_dp[child][0] = 1;
		}
		else if (_color[child] == 'G')
		{
			_dp[child][1] = 1;
		}
		else
		{
			_dp[child][2] = 1;
		}

		//遍历和child节点相连的节点，计算颜色数量
		//父节点要跳过
		for (auto& curNode : _tree[child])
		{
			//等于父节点跳过
			if (curNode == parent)
				continue;
			//递归计算左右子树的颜色数量
			dfsColorSum(curNode, child);
			//累加左右子树的数量
			_dp[child][0] += _dp[curNode][0];
			_dp[child][1] += _dp[curNode][1];
			_dp[child][2] += _dp[curNode][2];
		}
	}

	void dfsAnswer(int child, int parent)
	{
		//遍历当前节点的左右子树
		for (auto& curNode : _tree[child])
		{
			if (curNode == parent)
				continue;
			//砍掉当前子树的各色节点数量
			int numR = _totalR - _dp[curNode][0];
			int numG = _totalG - _dp[curNode][1];
			int numB = _totalB - _dp[curNode][2];

			//砍掉后父树有三种颜色 && 子树有三种颜色
			if (numR && numG && numB && _dp[curNode][0] && _dp[curNode][1] && _dp[curNode][2])
				++_ans;
			dfsAnswer(curNode, child);
		}
	}

	int calculateNum()
	{
		//计算以每个节点为根的每种颜色数量
		dfsColorSum(1, -1);
		//记录总数
		_totalR = _dp[1][0];
		_totalG = _dp[1][1];
		_totalB = _dp[1][2];

		dfsAnswer(1, -1);

		return _ans;
	}
};

int main()
{
	Solution sl;
	sl.getIO();
	cout << sl.calculateNum() << endl;

	return 0;
}