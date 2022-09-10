//https://leetcode-cn.com/problems/surface-area-of-3d-shapes/
//892. ��ά����ı����

//��N*N�������ϣ����Ƿ���һЩ1 * 1 * 1�������塣
//
//ÿ��ֵv = grid[i][j]��ʾv������������ڶ�Ӧ��Ԫ��(i, j)�ϡ�
//
//���㷵����������ı������

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        // three views ����ͼ���У������пն�
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
