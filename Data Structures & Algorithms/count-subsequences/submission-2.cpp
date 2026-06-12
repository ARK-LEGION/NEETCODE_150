class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        dp[0][0]=1;
        for (int j=0; j<=n; j++) dp[j][0]=1;
        for (int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
