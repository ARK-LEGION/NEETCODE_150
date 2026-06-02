class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,INT_MAX));
        for (int i=0; i<n; i++){
            for (int j=0; j<=amount; j++){
                if (j==0) dp[i][j] = 0;
                else dp[i][j] = min(((j-coins[i]>=0 && dp[i][j-coins[i]]!=INT_MAX)? dp[i][j-coins[i]] + 1 : INT_MAX), min((i-1>=0 ? dp[i-1][j] : INT_MAX),dp[i][j]));
            }
        }
        if (dp[n-1][amount]<0 || dp[n-1][amount]==INT_MAX) return -1;
        return dp[n-1][amount];
    }
};
