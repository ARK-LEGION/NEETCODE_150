class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        for (int j=0; j<n-1; j++){
            for (auto u:times){
                int node = u[0];
                int child=u[1];
                int d = u[2];
                if (dist[node]!=INT_MAX && dist[node]+d<dist[child]){
                    dist[child] = d+dist[node];
                }
            }
        }
        int ans=0;
        for (int i=1; i<=n; i++){
            ans=max(ans, dist[i]);
            if (ans==INT_MAX) return -1;
        }
        return ans;
    }
};
