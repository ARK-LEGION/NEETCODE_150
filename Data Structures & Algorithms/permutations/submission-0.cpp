class Solution {
public:
    void helper(int i, vector<int>&nums, vector<vector<int>>&ans){
        vector<int> temp;
        if (nums.size()==1) {
            ans.push_back({nums[0]});
            return;
        }
        for (int j=0; j<nums.size(); j++){
            if (j!=i) temp.push_back(nums[j]);
        }
        vector<vector<int>> dup;
        for (int j=0; j<temp.size(); j++){
            helper(j,temp,dup);
        }
        for (auto &u: dup){
            u.push_back(nums[i]);
            ans.push_back(u);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n =  nums.size();
        vector<vector<int>> ans;
        for (int j=0; j<n; j++) helper(j,nums,ans);
        return ans;
    }
};
