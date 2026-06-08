class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int start=0;
        for(int i=0; i<n; i++) start^=nums[i];
        return start;
    }
};
