class Solution {
public:
    void dfs(string& node, map<string,multiset<string>>&adj, vector<string>&ans){
        while (!adj[node].empty()){
            auto it = adj[node].begin();
            string v  =*it;
            adj[node].erase(it);
            dfs(v, adj,ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> adj;
        for (auto u:tickets){
            adj[u[0]].insert(u[1]);
        }
        vector<string> ans;
        string start = "JFK";
        dfs(start, adj,ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
