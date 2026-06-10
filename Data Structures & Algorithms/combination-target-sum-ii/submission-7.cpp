class Solution {
public:
    void helper(int i, int sum, vector<int>&arr, vector<int>&candidates, int target,vector<vector<int>>&ans){
        if (sum==target){
            ans.push_back(arr);
            return;
        }
        if (i==candidates.size()) return;
        
        if (sum+candidates[i]<=target){
            arr.push_back(candidates[i]);
            helper(i+1, sum+candidates[i], arr, candidates, target, ans);
            arr.pop_back();
        }
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++; 
        }
        helper(i+1,sum,arr,candidates, target,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n  = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>  init ={};
        helper(0,0,init,candidates,target,ans);
        return ans;
    }
};
