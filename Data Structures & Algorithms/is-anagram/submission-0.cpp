class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n!=m) return false;
        vector<int> a(26), b(26);
        for (int i=0; i<n; i++){
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        if (a==b) return true;
        return false;
    }
};
