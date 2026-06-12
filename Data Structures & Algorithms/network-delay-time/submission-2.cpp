class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        for (auto u:times){
            adj[u[0]].push_back(pair<int,int>{u[1],u[2]});
        }
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(pair<int,int>{0,k});
        while (!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d>dist[node]) continue;
            for(auto u:adj[node]){
                int  child = u.first;
                if (d+u.second<dist[child]){
                    dist[child] = u.second+d;
                    pq.push(pair<int,int>{dist[child],child});
                }
            }
        }
        int ans=0;
        for (int i=1; i<=n; i++){
            ans = max(dist[i],ans);
        }
        if (ans==INT_MAX) return -1;
        return ans;
    }
};
