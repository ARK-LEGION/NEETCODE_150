class Solution {
public:
    void helper(int i,int cur_sum, vector<int>& cur_arr, vector<vector<int>>&ans,vector<int>&nums, int target){
        if (i>=nums.size()) return;
        if (cur_sum==target){
            ans.push_back(cur_arr) ;
            return ;
        }
        if(cur_sum+nums[i]<=target){
            cur_arr.push_back(nums[i]);
            helper(i,cur_sum+nums[i], cur_arr,ans, nums,target);
            cur_arr.pop_back();
        }
        helper(i+1, cur_sum,cur_arr, ans,nums,target);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> init={};
        helper(0,0,init,ans, nums, target);
        for (auto u:ans){
            sort(ans.begin(), ans.end());
        }
        set<vector<int>> temp(ans.begin(), ans.end());
        vector<vector<int>> final(ans.begin(), ans.end());
        return ans;
    }
};
