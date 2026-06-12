class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if (k!=m+n)return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        dp[n][m]=1;
        for (int i=n; i>=0; i--){
            for (int j=m; j>=0; j--){
                if (i==n && j==m) continue;
                dp[i][j] = ((i+1<=n && dp[i+1][j]&&(s1[i]==s3[i+j]) ) ||( j+1<=m && dp[i][j+1]&&(s3[i+j]==s2[j])));
            }
        }
        return dp[0][0];
    }

};
