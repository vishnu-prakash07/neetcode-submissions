class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<tuple<int,int,int>> q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == 2)
                    q.push({i,j,0});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};
        while (!q.empty()){
            auto [x,y,t] = q.front();
            q.pop();
            time = max(t,time);

            for (int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                
                if (grid[nx][ny] != 1)
                    continue;
                
                grid[nx][ny] = 2;
                fresh--;
                q.push({nx,ny,t+1});
            }
        }
        if (fresh > 0)
            return -1;
        return time;
    }
};
