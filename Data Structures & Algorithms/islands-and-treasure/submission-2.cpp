class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == 0)
                    q.push({i,j});
            }
        }
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};

        while (!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for (int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                
                if (grid[nx][ny] == -1)
                    continue;
                
                if (grid[nx][ny] != INT_MAX) //already visited
                    continue;
                
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
};
