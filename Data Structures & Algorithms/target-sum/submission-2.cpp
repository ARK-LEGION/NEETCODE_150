class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans=0;
        for (int j=0; j<(1<<n); j++){
            int t=0;
            for (int i=0; i<n; i++){
                if ((1<<i)&j){
                    t+=nums[i];
                }
                else t-=nums[i];
            }
            if (t==target) ans++;
        }
        return ans;
        
    }
};
