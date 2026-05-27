class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for (int i=0; i<n; i++){
            m[nums[i]]++;
        }
        int cnt=1;
        int ans=0;
        for (auto u : m){
            int prev = u.first -1;
            if (m[prev]>0){
                cnt++;
            }
            else cnt=1;

            ans = max(ans, cnt);
        }
        return ans;
    }
};
