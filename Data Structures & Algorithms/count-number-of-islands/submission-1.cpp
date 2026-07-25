class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int r,int c){
        int n = grid.size();
        int m = grid[0].size();
        if (r >= n || r < 0 || c >= m || c < 0)
            return;
        if (grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j] == '1'){
                    dfs(grid,i,j);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};
