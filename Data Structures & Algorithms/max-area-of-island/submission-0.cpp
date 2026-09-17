class Solution {
public:

    int dfs(int x,int y,vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n)
            return 0;
        if (grid[x][y] == 0)
            return 0;
        grid[x][y] = 0;
        return 1 + dfs(x+1,y,grid) + dfs(x-1,y,grid) + dfs(x,y+1,grid) + dfs(x,y-1,grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for (int i=0;i<m;i++){
            for (int j =0;j<n;j++){
                if (grid[i][j] == 1)
                    maxArea = max(maxArea,dfs(i,j,grid));
            }
        }

        return maxArea;
    }
};
