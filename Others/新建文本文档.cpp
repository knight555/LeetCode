//https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
//892. 三维形体的表面积

//在N*N的网格上，我们放置一些1 * 1 * 1的立方体。
//
//每个值v = grid[i][j]表示v个正方体叠放在对应单元格(i, j)上。
//
//请你返回最终形体的表面积。

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        // three views 三视图不行，可能有空洞
        if(grid.size()==0)
            return 0;
        int u = view(grid,'u'),l = view(grid,'l'), f = view(grid,'f');
        cout << u << " " << l << " " << f << endl;
        return view(grid,'u')+view(grid,'l')+view(grid,'f');
    }
    int view(vector<vector<int>> grid, char c){
        int area = 0;
        if(c=='u'){
            for(int i=0;i<grid.size();i++)
                for(int j=0;j<grid[0].size();j++)
                    area += grid[i][j]==0?0:1;
        }
        if(c=='l'){
            for(int i=0;i<grid.size();i++){
                int maxheight = 0;
                for(int j=0;j<grid[0].size();j++)
                    maxheight = maxheight>grid[i][j]?maxheight:grid[i][j];
                area += maxheight*1;
            }     
        }
        if(c=='f'){
            for(int i=0;i<grid[0].size();i++){
                int maxheight = 0;
                for(int j=0;j<grid.size();j++)
                    maxheight = maxheight>grid[j][i]?maxheight:grid[j][i];
                area += maxheight*1;
            }
        }
        return area*2;
    }
};
