class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<(1<<n);i++){
            vector<int> temp;
            for (int j=0; j<n; j++){
                // while(j+1<n && nums[j+1]==nums[j] && nums[j+1])
                if ((1<<j)&i){
                    temp.push_back(nums[j]);
                }
            }
            ans.insert(temp);
        }
        vector<vector<int>> v(ans.begin(), ans.end());
        return v;   
    }
};
