class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==1) return 0;
        if (n==2){
            return max(0, prices[1]-prices[0]);
        }
        vector<vector<int>> dp(n,vector<int>(2,0));
        vector<int> last(n);
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        last[0] = 0;

        for (int i=1; i<n; i++){
            
            
            if (dp[i-1][0] - prices[i] > dp[i-1][1]){
                last[i] = i;
            }
            else if (dp[i-1][0] - prices[i] == dp[i-1][1]){
                if (prices[i] < prices[last[i-1]]){
                    last[i]  = i;
                }
                else last[i] = last[i-1];
            }
            else last[i] = last[i-1];
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);

        }

        return max(dp[n-1][0], dp[n-1][1]+prices[last[n-1]]);
    }
};