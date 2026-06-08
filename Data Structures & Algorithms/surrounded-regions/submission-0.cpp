class Solution {
public: 
    void dfs(int x, int y, vector<vector<char>>&board){
        int n  = board.size();
        int m = board[0].size();
        board[x][y]='A';
        for (int dx=-1; dx<=1; dx++){
            for (int dy=-1; dy<=1; dy++){
                if (dx*dy==0 && x+dx>=0 && x+dx<n && y+dy<m && y+dy>=0 && board[x+dx][y+dy]=='O'){
                    dfs(x+dx, y+dy, board);
                }
            }
        }
        // board[x][y]='A';
    }
    void solve(vector<vector<char>>& board) {
        int n  = board.size();
        int m = board[0].size();
        for (int i=0; i<n; i++) {
            if (board[i][0]=='O')dfs(i,0,board);
            if (board[i][m-1]=='O')dfs(i,m-1,board);
        }
        for (int i=0; i<m; i++) {
            if (board[0][i]=='O')dfs(0,i,board);
            if (board[n-1][i]=='O')dfs(n-1,i,board);
        }
        for (int i=0; i<n; i++){
            for (int j=0;j<m; j++){
                if(board[i][j]=='A') board[i][j]='O';
                else if (board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
