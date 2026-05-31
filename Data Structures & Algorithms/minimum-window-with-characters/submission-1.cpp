class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int min_i=n, min_j = -1;
        unordered_map<char,int> x;
        for (int i=0; i<m ;i++) x[t[i]]++;
        int cnt=0;
        int numd = x.size();
        int j=0;
        for (int i=0; i<n; i++){
            x[s[i]]--;
            if (x[s[i]]==0) cnt++;
            bool f=false;
            while (j<=i && cnt>=numd){
                f=true;
                x[s[j]]++;
                if (x[s[j]]>0) cnt--;
                j++;
            }
            if (f)j--, cnt++, x[s[j]]--;
            if (cnt==numd && (min_i-min_j+1 > i-j+1)){
                min_i = i;
                min_j = j;
            }
        }
        if (min_j==-1) return "";
        string ans = s.substr(min_j, min_i - min_j + 1);
        return ans;
    }
};
