class Solution {
public:

    void dfs(int x, int y, vector<vector<int>>&vis, vector<vector<int>>&grid, int&cnt){
        vis[x][y]=1;
        cnt++;
        int n = grid.size();
        int m = grid[0].size();
        for (int dx=-1; dx<=1; dx++){
            for (int dy=-1; dy<=1; dy++){
                if (x+dx>=0 && x+dx<=n-1 && y+dy>=0 && y+dy<=m-1 && dx*dy==0 && !vis[x+dx][y+dy] && grid[x+dx][y+dy]==1){
                    vis[x+dx][y+dy]=1;
                    dfs(x+dx, y+dy, vis,  grid,cnt);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (!vis[i][j] && grid[i][j]==1){
                    vis[i][j]=1;
                    int cnt=0;
                    dfs(i,j,vis,grid,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
