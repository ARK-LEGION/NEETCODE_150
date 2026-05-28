class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i=0; i<n-2; i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while (j<k){
                if (nums[j]+nums[k]>-nums[i]) k--;
                else if (nums[j]+nums[k]<-nums[i]) j++;
                else {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
