class Solution {
public:
    // void helper(int i,int cur_sum, vector<int>& cur_arr, vector<vector<int>>&ans,vector<int>&nums, int target){
    //     if (i>=nums.size()) return;
    //     if (cur_sum==target){
    //         ans.push_back(cur_arr) ;
    //         return ;
    //     }
    //     if(cur_sum+nums[i]<=target){
    //         cur_arr.push_back(nums[i]);
    //         helper(i,cur_sum+nums[i], cur_arr,ans, nums,target);
    //         cur_arr.pop_back();
    //     }
    //     helper(i+1, cur_sum,cur_arr, ans,nums,target);
    //     return ;
    // }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<vector<vector<int>>> dp(target+1);
        dp[0]={{}};
        int n = nums.size();
        for (int j=0; j<n; j++){
            for (int i=0; i<=target; i++){
                if (i-nums[j]>=0){
                    for (auto u:dp[i-nums[j]]){
                        u.push_back(nums[j]);
                        dp[i].push_back(u);
                    }
                }
            }
        } 
        return dp[target];
    }
};
