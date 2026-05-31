class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m =s2.size();
        unordered_map<char,int> x;
        for (int i=0; i<n; i++) x[s1[i]]++;
        int cnt=0;
        int j=0;
        for (int i=0; i<m; i++){
            x[s2[i]]--;
            // if (x[s2[i]]==0) cnt++;
            
            while (x[s2[i]]<0){
                // if (x[s2[j]]==0) cnt--;
                x[s2[j]]++;
                j++;
            }

            if (i-j+1==n) return true;
        }
        return false;
    }
};
