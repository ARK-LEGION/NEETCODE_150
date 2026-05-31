class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        vector<int> dp(n);
        dp[0]=nums[0];
        //taking 0 only
        dp[1]=nums[0];
        for (int i=2; i<n-1; i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        vector<int> dp2(n);
        dp2[1]=nums[1];
        for (int i=2; i<n; i++){
            dp2[i] = max(nums[i]+dp2[i-2], dp2[i-1]);
        }
        return max(dp[n-2], dp2[n-1]);
    }
};
