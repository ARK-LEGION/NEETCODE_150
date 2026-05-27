class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;
        int n =  strs.size();
        for (int i=0; i<n; i++){
            vector<int> a(26);
            for (int j=0; j<strs[i].size(); j++){
                a[strs[i][j]-'a']++;
            }
            m[a].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto u:m){
            ans.push_back(u.second);
        }
        return ans;
    }
};
