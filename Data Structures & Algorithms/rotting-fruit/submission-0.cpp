class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int cnt=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
                if (grid[i][j]==1) cnt++;
            }
        }
        int maxi=0;
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int dx=-1; dx<=1; dx++){
                for (int dy=-1; dy<=1; dy++){
                    if (dx*dy==0 && x+dx<n && x+dx>=0 && y+dy<m && y+dy>=0){
                        if (grid[x+dx][y+dy]==1){
                            cnt--;
                            grid[x+dx][y+dy]=1+grid[x][y];
                            q.push({x+dx, y+dy});
                            maxi = max(maxi,grid[x+dx][y+dy]);
                        }
                    }
                }
            }
        }
        if (cnt>0) return -1;
        return max(0,maxi-2);
    }
};
