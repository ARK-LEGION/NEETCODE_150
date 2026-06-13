class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r=n-1, u = 0, d = m-1;
        int cur_x = 0, cur_y = 0;
        int cnt=0;
        vector<int> ans;
        while (cnt<m*n){
            for (int j=l; j<=r; j++){
                ans.push_back(matrix[u][j]);
                cnt++;
            }
            if (cnt==m*n) break;
            u++;
            for (int i=u; i<=d; i++){
                ans.push_back(matrix[i][r]);
                cnt++;
            }
            if (cnt==m*n) break;
            r--;
            for (int j=r; j>=l; j--){
                ans.push_back(matrix[d][j]);
                cnt++;
            }
            if (cnt==m*n) break;
            d--;
            for (int i=d; i>=u; i--){
                ans.push_back(matrix[i][l]);
                cnt++;
            }
            if (cnt==m*n) break;
            l++;
        }
        return ans;
    }
};
