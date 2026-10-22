class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        int levelSize = 0;
        queue<pair<int,int>> q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                }
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0)
            return 0;
        int timeReq = 0;
        
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
        while (!q.empty()){
            levelSize = q.size();
            bool rottenThisMinute = false;
            while (levelSize--){
                auto [x,y] = q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if (newX < 0 || newY < 0 || newX >= n || newY >= m)
                        continue;
                    if (grid[newX][newY] == 1){
                        q.push({newX,newY});
                        grid[newX][newY] = 2;
                        fresh--;
                        rottenThisMinute = true;
                    }
                }
            }
            if (rottenThisMinute)
                timeReq++;
        }
        if (fresh == 0)
            return timeReq;
        return -1;
    }
};
