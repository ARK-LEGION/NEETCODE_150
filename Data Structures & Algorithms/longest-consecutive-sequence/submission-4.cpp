class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> m;
        for (int i=0; i<n; i++){
            m.insert(nums[i]);
        }
        int cnt=1;
        int ans=0;
        for (int u : nums){
            if (m.find(u) != m.end() && m.find(u-1)==m.end()){
                cnt=1;
                int curr = u;
                while (m.find(curr+1)!=m.end()){
                    cnt++;
                    curr++;
                }
                ans=  max(ans,cnt);
            }
        }

        return max(ans, (int)m.size() > 0 ? ans : (int)m.size());
    
    }
};
