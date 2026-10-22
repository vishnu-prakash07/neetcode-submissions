class Solution {
public:

    int solve(int x,int y,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if (x < 0 || y < 0 || x >= n || y >= m)
            return 0;
        
        if (grid[x][y] == 0)
            return 0;
        
        grid[x][y] = 0;//mark as visited

        int up = solve(x-1,y,grid);
        int down = solve(x+1,y,grid);
        int left = solve(x,y-1,grid);
        int right = solve(x,y+1,grid);

        return 1 + up + down + left + right;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j] == 1){
                    int area = solve(i,j,grid);
                    res = max(res,area);
                }
            }
        }
        return res;
    }
};
