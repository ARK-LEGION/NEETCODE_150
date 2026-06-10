class Solution {
public:
    void helper(int i, vector<int>&nums, vector<vector<int>>&ans){
        if (i==nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        for (int j=i; j<nums.size(); j++){
            swap(nums[j], nums[i]);
            helper(i+1, nums,ans);
            swap(nums[j], nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n =  nums.size();
        vector<vector<int>> ans;
        helper(0,nums,ans);
        return ans;
    }
};
