class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l=0, r=n-1;
        while (l<r){
            int m =(l+r)/2;
            if (nums[m]==target) return m;

            if (nums[m]>target){
                if (target>nums[n-1]){
                    r=m;
                }
                else if (nums[m]>nums[n-1] && target<=nums[n-1]) l=m+1;
                else r=m;
            }else{
                if (nums[m]>nums[n-1]){
                    l=m+1;
                }
                else if (nums[m]<=nums[n-1] && target>nums[n-1]) r=m;
                else if(target<=nums[n-1]) l=m+1;
            }
        }
        if (nums[l]!=target) return -1;
        return l;
    }
};
