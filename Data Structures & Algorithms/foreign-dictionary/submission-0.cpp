class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n  = words.size();
        string topo;
        vector<vector<int>> adj(26);
        vector<int>ind(26,0);
        vector<int> seen(26,0);
        int cnt=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<words[i].size(); j++){
                if (seen[words[i][j]-'a']==0){
                    cnt++;
                    seen[words[i][j]-'a']++;
                }
            }
        }
        for (int i=0; i<n-1; i++){
            bool f=false;
            for (int j=0; j<min((int)words[i].size(),(int)words[i+1].size()); j++){
                if (words[i][j]!=words[i+1][j]){
                    f=true;
                    adj[words[i][j]-'a'].push_back(words[i+1][j]-'a');
                    ind[words[i+1][j]-'a']++;
                    break;
                }
            }
            if (!f){
                if (words[i].size()>words[i+1].size()) return "";
            }
        }

        queue<int> q;
        for(int i=0; i<26; i++){
            if (seen[i] && ind[i]==0){
                q.push(i);
            }
        }
        while (!q.empty()){
            int node = q.front();
            topo.push_back(node+'a');
            q.pop();
            for (auto u:adj[node]){
                ind[u]--;
                if (ind[u]==0) q.push(u);
            }
        }
        if (topo.size()!=cnt) return "";
        return topo;


    }
};
