class Solution {
public:
    using pii = pair<int,int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>>adj(n);
        for (auto u:flights){
            adj[u[0]].push_back({u[1],u[2]});
        }
        queue<vector<int>> q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,0,src});
        int ans=INT_MAX;
        while (!q.empty()){
            int num = q.front()[0];
            int d = q.front()[1];
            int node = q.front()[2];
            q.pop();
            if (node==dst){
                ans=min(ans,d);
            }
            // if (d>dist[node]) continue;
            for (auto u:adj[node]){
                int child = u.first;
                int edW = u.second;
                if (d+edW < dist[child] && num+1<=k+1){
                    dist[child] = d+edW;
                    q.push({num+1, d+edW, child});
                }
            }
        }

        if (dist[dst]==INT_MAX) return -1;
        return ans;
    }
};
