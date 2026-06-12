using pii = pair<int,int>;
class Solution {
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<pii>>> adj(n, vector<vector<pii>>(m));
        vector<vector<vector<pii>>> rev(n, vector<vector<pii>>(m));
        vector<vector<int>>ind(n,vector<int>(m,0));
        for (int x=0;x<n; x++){
            for (int y=0; y<m; y++){
                for (int dx=-1; dx<=1; dx++){
                    for (int dy=-1; dy<=1; dy++){
                        if (dx*dy==0 && x+dx>=0 && x+dx<n && y+dy>=0 && y+dy<m){
                            if(matrix[x+dx][y+dy]>matrix[x][y]){
                                adj[x][y].push_back({x+dx,y+dy});
                                rev[x+dx][y+dy].push_back({x,y});
                                ind[x+dx][y+dy]++;
                            }
                        }
                    }
                }
            }
        }
        queue<pii> q;
        pii start = {0,0};
        vector<vector<int>> dp(n,vector<int>(m,0));
        for (int i=0;i<n; i++){
            for (int j=0; j<m; j++){
                if (ind[i][j]==0)start=pii{i,j},q.push({i,j}),dp[i][j]=1;
            }
        }
        vector<pii> topo;
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            topo.push_back({x,y});
            q.pop();
            for (auto u:adj[x][y]){
                ind[u.first][u.second]--;
                if (ind[u.first][u.second]==0){
                    q.push({u.first,u.second});
                }
            }
        }
        int ans=1;
        

        for (int i=0; i<topo.size(); i++){
            pii node = topo[i];
            int maxi= INT_MIN;
            for (auto u:rev[node.first][node.second]){
                if(dp[u.first][u.second]>maxi){
                    maxi = dp[u.first][u.second];
                }

            }
            if (maxi!=INT_MIN) dp[node.first][node.second]=maxi+1, ans=max(ans,1+maxi);
        }
        return ans;

    }
};
