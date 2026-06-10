class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<(1<<n);i++){
            vector<int> temp;
            bool f=false;
            for (int j=0; j<n; j++){
                if (j+1<n && nums[j+1]==nums[j] && (!((1<<(j+1))&i)) &&  ((1 << j) & i)) {
                    f=true;
                    break;
                }
               
                if ((1<<j)&i){
                    temp.push_back(nums[j]);
                }
            }
            if (!f)ans.push_back(temp);
        }
        return ans;   
    }
};
