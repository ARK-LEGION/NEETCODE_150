class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1;
        int i=0;
        while (i<=r){
            if (l>=r) break;
            if (nums[i]==0 ) swap(nums[i], nums[l]), l++,i++;
            else if (nums[i]==2 ) swap(nums[i], nums[r]) ,r--;
            else i++;
        }
    }
};