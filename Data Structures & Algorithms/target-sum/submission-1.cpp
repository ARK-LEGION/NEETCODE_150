class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1,0));
        for (int i=0; i<=n; i++) dp[i][0]=1;
        for (int i=1; i<=n; i++){
            for (int j=0; j<=target;j++){
                dp[i][j] = (j-nums[i-1]>=0 ? dp[i-1][j-nums[i-1]] : 0) + (j+nums[i-1]<=target ? dp[i-1][j+nums[i-1]] : 0);
            }
        }
        return dp[n][target];
    }
};
