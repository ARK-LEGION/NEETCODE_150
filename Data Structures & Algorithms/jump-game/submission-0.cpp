class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 1;
        int maxi=nums[0];
        int i=0;
        while (i<n-1){
            maxi = max(maxi,nums[i]);
            maxi--;
            if (maxi<0) return 0;
            i++;
        }
        return 1;
    }
};
