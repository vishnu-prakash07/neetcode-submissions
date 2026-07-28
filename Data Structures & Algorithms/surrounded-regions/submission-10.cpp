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
        for (int j=0;j<m;j++){
            if (board[0][j] == 'O'){
                dfsCheck(0,j,board,'O','-');
            }
            if (board[n-1][j] == 'O'){
                dfsCheck(n-1,j,board,'O','-');
            }
        }
        for (int i=0;i<n;i++){
            if (board[i][0] == 'O'){
                dfsCheck(i,0,board,'O','-');
            }
            if (board[i][m-1] == 'O'){
                dfsCheck(i,m-1,board,'O','-');
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j] == 'O')
                    dfsCheck(i,j,board,'O','X');
                else if (board[i][j] == '-')
                    board[i][j] = 'O';
            }
        }
    }
};
