class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n==1) return 0;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>> > pq;
        pq.push({grid[0][0],0,0});
        while (!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int d = pq.top()[0];
            pq.pop();
            if(d>dist[x][y]) continue;
            for (int dx=-1; dx<=1; dx++){
                for (int dy=-1; dy<=1; dy++){
                    if (dx*dy==0 && x+dx<n && y+dy<n && x+dx>=0 && y+dy>=0){
                        if (max(d, grid[x+dx][y+dy]) < dist[x+dx][y+dy]){
                            dist[x+dx][y+dy] = max(d, grid[x+dx][y+dy]);
                            pq.push({dist[x+dx][y+dy], x+dx, y+dy});
                        }
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
