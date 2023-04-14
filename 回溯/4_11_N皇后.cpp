//N皇后
//https://leetcode.cn/problems/n-queens/submissions/
class Solution {
public:
    vector<vector<string>> _ans;
    vector<string> _board;

public:
    bool used(const int& n, int row, int col)
    {
        //检查同一列是否有Q
        for (int i = row; i >= 0; i--)
        {
            if (_board[i][col] == 'Q')
                return false;
        }


        //                      /
        // 检查右上斜角有没有Q: /____
        // 右上则：行 - 1，列 + 1
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
        {
            if (_board[i][j] == 'Q')
                return false;
        }

        //                    \
        // 检查左上斜角有没有Q：\—————
        // 左上则：行- 1，列 - 1
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        {
            if (_board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backTrack(const int& n, int row)
    {
        if (row >= n)
        {
            _ans.emplace_back(_board);
            return;
        }

        // 控制列
        for (int col = 0; col < n; ++col)
        {
            if (used(n, row, col))
            {
                _board[row][col] = 'Q';
                backTrack(n, row + 1);
                _board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        _board = vector<string>(n, string(n, '.'));
        backTrack(n, 0);

        return _ans;
    }
};