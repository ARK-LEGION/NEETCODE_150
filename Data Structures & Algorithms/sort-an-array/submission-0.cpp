class Solution {
public:
    void mergesort(int left, int right, vector<int>&nums){
        int n = nums.size();
        if (left==right) return;
        int mid = (left+right)/2;
        mergesort(left, mid, nums);
        mergesort(mid+1, right, nums);
        int i=left, j = mid+1, k=0;
        vector<int> temp(right-left+1);
        while (i<=mid && j<=right){
            if (nums[i]>nums[j]){
                temp[k] = nums[j];
                j++;
            }
            else{
                temp[k] = nums[i];
                i++;
            }
            k++;
        }
        while (i<=mid){
            temp[k] = nums[i];
            i++;
            k++;
        }
        while (j<=right){
            temp[k] = nums[j];
            j++;
            k++;
        }
        for (int p=left; p<=right; p++){
            nums[p] = temp[p-left];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n  = nums.size();
        if (n==1) return nums;
        mergesort(0,n-1,nums);
        return nums;
    }
};