class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        for (int i=0; i<n; i++) s+=nums[i];
        if (s%2==1) return false;
        int target = s/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1));
        for (int i=0; i<n; i++){
            dp[i][0]=1;
        }
        
        for(int i=1; i<=n; i++){
            for (int j=1;j<=target; j++){
                dp[i][j] |= (dp[i-1][j] | (j-nums[i-1]>=0 ? dp[i-1][j-nums[i-1]] : 0));
            }
        }

        return dp[n][target];
        
    }
};
