class Solution {
map<int,string> m;
public:
    int mod = 1e9 + 7;
    string encode(vector<string>& strs) {
        string ret;
        for (int i=0; i<strs.size(); i++){
            int val = 1;
            int hash=0;
            for (int j=0; j<strs[i].size(); j++){
                hash = (hash + val*((int)strs[i][j]))%mod;
                val = (val*257)%mod;
            }
            m[hash]=strs[i];
            string temp   = to_string(hash);
            for (int j=0; j<temp.size(); j++){
                ret.push_back(temp[j]);
            }
            ret.push_back(' ');
        }
        return ret;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while (i<s.size()){
            if (i==s.size()-1) break;
            string temp;
            while (i<s.size() && s[i]!=' '){
                temp.push_back(s[i]);
                i++;
            }
            int v = stoi(temp);
            ans.push_back(m[v]);
            i++;
        }
        return ans;
    }
}; 