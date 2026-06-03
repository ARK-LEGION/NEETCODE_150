class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        for (int i=0; i<n; i++) s+=nums[i];
        if (s%2==1) return false;
        int target = s/2;
        // vector<vector<int>> dp(n+1,vector<int>(target+1));
        // for (int i=0; i<n; i++){
        //     dp[i][0]=1;
        // }
        vector<int>prev(target+1);
        vector<int> cur(target+1);
        prev[0]=cur[0]=1;
        for(int i=1; i<=n; i++){
            for (int j=1;j<=target; j++){
                cur[j] |= (prev[j] | (j-nums[i-1]>=0 ? prev[j-nums[i-1]] : 0));
            }
            prev=cur;
        }

        return prev[target];
        
    }
};
