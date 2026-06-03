class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0, maxi=0, max_elem=INT_MIN;
        for (int i=0; i<n; i++){
            sum+=nums[i];
            if (sum<0) sum=0;
            maxi = max(maxi,sum);
            max_elem= max(max_elem,nums[i]);
        }
        if (max_elem<=0) return max_elem;
        return maxi;
    }
};
