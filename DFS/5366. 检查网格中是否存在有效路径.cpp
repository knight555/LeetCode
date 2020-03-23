//https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/
//5366. 检查网格中是否存在有效路径

#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct Point {
	bool l, r, u, d;
	Point(bool l, bool r, bool u, bool d) :l(l), r(r), u(u), d(d) {}
}Point;
class Solution {
public:
	int m, n;
	Point *ptype;
	bool hasValidPath(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid[0].size();
		Point plr(1, 1, 0, 0), plu(1, 0, 1, 0), pld(1, 0, 0, 1), pru(0, 1, 1, 0), prd(0, 1, 0, 1), pud(0, 0, 1, 1);
		ptype = new Point[6]{ plr,pud,pld,prd,plu,pru };
		for (int i = 0;i < 6;i++) {
			cout << ptype[i].l << " " << ptype[i].r << " " << ptype[i].u << " " << ptype[i].d;
			cout << endl;
		}
		dfs(grid, 0, 0);
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++)
				cout << grid[i][j] << " ";
			cout << endl;
		}
		return grid[m - 1][n - 1] == 0;
	}
	void dfs(vector<vector<int>>& grid, int x, int y) {
		if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
		{
			int c = grid[x][y];
			cout << c << endl;
			grid[x][y] = 0;
			//go left    // make sure the gird I want dfs is valid (grid[x][y - 1]!=0)
			if (y-1 >= 0 && ptype[c - 1].l && grid[x][y - 1] && ptype[grid[x][y-1] - 1].r)
				dfs(grid, x, y-1);
			//go right
			if (y + 1 < n && ptype[c - 1].r && grid[x][y + 1] && ptype[grid[x][y + 1] - 1].l)
				dfs(grid, x, y + 1);
			//go up
			if (x - 1 >= 0 && ptype[c - 1].u && grid[x - 1][y] && ptype[grid[x - 1][y] - 1].d)
				dfs(grid, x - 1, y);
			//go down
			if (x+1 < m && ptype[c - 1].d && grid[x + 1][y] && ptype[grid[x+1][y] - 1].u)
				dfs(grid, x + 1, y);
				
		}
	}
};

int main()
{
	vector<vector<int>> grid = { {2,1,3},
								 {6,5,2} };//true
	cout << Solution().hasValidPath(grid);
	return 0;

}