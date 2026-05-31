class Solution {
public:
    int characterReplacement(string s, int k) {
        int n  = s.size();
        unordered_map<char,int> m;
        int j=0;
        int ans=0;
        int maxi = 0;
        for (int i=0; i<n; i++){
            m[s[i]]++;
            maxi = max(maxi, m[s[i]]);
            while (j<=i && i-j+1-maxi>k){
                m[s[j]]--;
                // maxi--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
