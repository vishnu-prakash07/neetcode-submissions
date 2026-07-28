class Solution {
public:

    void dfsCheck(int r,int c,vector<vector<char>>& board,char key,char replace){
        int n = board.size();
        int m = board[0].size();

        if (r >= n || r < 0 || c >= m || c < 0)
            return;
        
        if (board[r][c] != key)
            return;
        
        board[r][c] = replace;
        
        dfsCheck(r+1,c,board,key,replace);
        dfsCheck(r,c+1,board,key,replace);
        dfsCheck(r-1,c,board,key,replace);
        dfsCheck(r,c-1,board,key,replace);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<pair<int,int>> replace;
        for (int j=0;j<m;j++){
            if (board[0][j] == 'O'){
                dfsCheck(0,j,board,'O','-');
                replace.push_back({0,j});
            }
            if (board[n-1][j] == 'O'){
                dfsCheck(n-1,j,board,'O','-');
                replace.push_back({n-1,j});
            }
        }
        for (int i=0;i<n;i++){
            if (board[i][0] == 'O'){
                dfsCheck(i,0,board,'O','-');
                replace.push_back({i,0});
            }
            if (board[i][m-1] == 'O'){
                dfsCheck(i,m-1,board,'O','-');
                replace.push_back({i,m-1});
            }
        }
        for (int i=1;i<n-1;i++){
            for (int j=1;j<m-1;j++){
                if (board[i][j] == 'O')
                    dfsCheck(i,j,board,'O','X');
            }
        }
        for (auto &it : replace)
            dfsCheck(it.first,it.second,board,'-','O');
    }
};
