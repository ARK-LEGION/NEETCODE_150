class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        target+=1000;
        vector<vector<int>> dp(n+1, vector<int>(2001,0));
        dp[0][1000]=1;
        for (int i=1; i<=n; i++){
            for (int j=0; j<=2e3 ;j++){
                dp[i][j] = (j-nums[i-1]>=0 ? dp[i-1][j-nums[i-1]] : 0) + (j+nums[i-1]<=2e3 ? dp[i-1][j+nums[i-1]] : 0);
            }
        }
        return dp[n][target];
    }
};
