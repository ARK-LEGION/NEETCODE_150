class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> psum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        psum.resize(n+1,vector<int>(m+1,0));
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
int sumRegion(int row1, int col1, int row2, int col2) {
        // Shift all coordinates by +1 to map to the 1-indexed psum array
        return psum[row2 + 1][col2 + 1] 
             - psum[row1][col2 + 1] 
             - psum[row2 + 1][col1] 
             + psum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */