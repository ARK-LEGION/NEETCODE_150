class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        for(auto u:adj[node]){
            if (!vis[u]){
                dfs(u,vis,adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto u:edges){
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if (!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
