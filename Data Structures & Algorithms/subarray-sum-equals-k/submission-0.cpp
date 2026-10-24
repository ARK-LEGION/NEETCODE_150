class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n+1);
        map<int,int> ms;
        int ans=0;
        
        for (int i=1; i<=n; i++){
            pre[i] = pre[i-1] + nums[i-1];
            ms[pre[i]]++;
        }
        
        for (int i=0; i<n; i++){
            ans+=ms[pre[i]+k];
            ms[pre[i+1]]--;
        }

        return ans;
        
    }
};