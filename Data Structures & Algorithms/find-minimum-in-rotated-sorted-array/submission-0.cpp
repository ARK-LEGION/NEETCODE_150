class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        int l=0, r=n-1;
        while (l<r){
            int m=(l+r)/2;
            if (nums[m]>nums[n-1]){
                l=m+1;
            }
            else r=m;
        }
        return nums[l];
    }
};
