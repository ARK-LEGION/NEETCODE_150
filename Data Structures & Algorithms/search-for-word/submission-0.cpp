class Solution {
public:
    bool helper(int x,int y,int id,vector<vector<bool>>&seen,vector<vector<char>>& board, string& word ){
        int n = board.size();
        int m = board[0].size();
        if (id==word.size()-1 && board[x][y]==word[id]) return true;
        bool f=false;
        if (board[x][y]==word[id]){
            seen[x][y]=1;
            if (x+1<n && !seen[x+1][y])f|=helper(x+1, y, id+1,seen,board,word);
            if (x-1>=0 && !seen[x-1][y])f|=helper(x-1, y, id+1,seen,board,word);
            if (y-1>=0 && !seen[x][y-1])f|=helper(x, y-1, id+1,seen,board,word);
            if (y+1<m && !seen[x][y+1])f|=helper(x, y+1, id+1,seen,board,word);
            seen[x][y]=0;
        }
        return f;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        string cur="";
        vector<vector<bool>>seen(n,vector<bool>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(i, j, 0, seen, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
