class Solution {
private:
    bool isSafe(int row, int col, vector<string>&cur,int n){
        for(int i=0; i<row; i++){
            if (cur[i][col]=='Q') return false;
        }
        for (int i=row, j=col; i>=0 && j>=0; i--, j--){
            if (cur[i][j]=='Q') return false;
        }
        for (int i = row, j=col; i>=0 && j<n; i--, j++){
            if (cur[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(int row, vector<string>&cur, vector<vector<string>>&ans, int n){
        if (row==n){
            ans.push_back(cur);
            return;
        }
        for (int col=0; col<n; col++){
            if (isSafe(row, col, cur, n)){
                cur[row][col] = 'Q';
                helper(row+1, cur,ans,n);
                cur[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur;
        string s="";
        for (int i=0; i<n; i++) s+='.';
        for (int i=0; i<n; i++) cur.push_back(s);
        helper(0,cur,ans,n);
        return ans;
    }
};
