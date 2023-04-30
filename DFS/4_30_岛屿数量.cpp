//https://leetcode.cn/problems/number-of-islands/
//200. 岛屿数量
class Solution {
public:
	//深度优先遍历
    void dfs(vector<vector<char>>& grid, int row, int col) {
        //左右边界
		if (row < 0 || row >= grid.size()) return;
		//上下边界
        if (col < 0 || col >= grid[0].size()) return;
		//遇到0返回
        if (grid[row][col] == '0') return;

		//标记该位置遍历过
        grid[row][col] = '0';

		//深度遍历上下左右四个位置
        dfs(grid, row + 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row - 1, col);
        dfs(grid, row, col - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0') 
                    continue;
				//如果该位置是陆地，从该位置深度优先遍历，把该位置所在陆地全部标记为0
				//标记为0后增加计数，全部遍历一遍就能得到答案
                else {
                    dfs(grid, i, j);
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};