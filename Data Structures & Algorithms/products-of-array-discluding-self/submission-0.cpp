class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int cnt=0;
        int idx=-1;
        for(int i=0; i<n; i++) {
            if (nums[i] == 0) {
                cnt++;
                idx = i;
            }
        }
        if (cnt>1) return ans;
        else if (cnt==1){
            int p=1;
            for (int i=0; i<n; i++){
                if (nums[i]==0) continue;
                p*=nums[i];
            }
            ans[idx]=p;
            return ans;
        } 
        //cnt=0;
        long long p  =1;
        for (int i=0; i<n; i++) p*=(long long)nums[i];
        for (int i=0;  i<n; i++){
            long long r = p/(long long) nums[i];
            ans[i] = (int)r;
        }
        return ans;

    }
};
