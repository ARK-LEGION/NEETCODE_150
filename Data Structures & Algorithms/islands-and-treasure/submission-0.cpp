class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
    
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int dx=-1; dx<=1; dx++){
                for (int dy=-1; dy<=1; dy++){
                    if (dx*dy==0 && x+dx>=0 && x+dx<m && y+dy<n && y+dy>=0){
                        if (grid[x+dx][y+dy]==INT_MAX){
                            grid[x+dx][y+dy] = 1 + grid[x][y];
                            q.push({x+dx, y+dy});
                        }
                    }
                }
            }
        }
    }
};
