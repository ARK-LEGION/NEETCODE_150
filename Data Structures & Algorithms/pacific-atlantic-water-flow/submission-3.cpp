class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int maxi = -1;
            int cnt = 1;
            int x = -1, y = -1;
            for (int i = 0; i < n; i++) {
                if (heights[i][j] > maxi) {
                    maxi = heights[i][j];
                    cnt = 1;
                    x = i, y = j;
                } else if (heights[i][j] == maxi) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                q.push({x, y});
            } else {
                int f = -1, l = -1;
                for (int i = 0; i < n; i++) {
                    if (heights[i][j] == maxi) {
                        if (f == -1)
                            f = i;
                        else
                            l = i;
                    }
                }
                if (l - f + 1 == cnt) {
                    for (int i = f; i <= l; i++) {
                        q.push({i, j});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int maxi = -1;
            int cnt = 1;
            int x = -1, y = -1;
            for (int j = 0; j < m; j++) {
                if (heights[i][j] > maxi) {
                    maxi = heights[i][j];
                    cnt = 1;
                    x = i, y = j;
                } else if (heights[i][j] == maxi) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                q.push({x, y});
            } else {
                int f = -1, l = -1;
                for (int j = 0; j < m; j++) {
                    if (heights[i][j] == maxi) {
                        if (f == -1)
                            f = j;
                        else
                            l = j;
                    }
                }
                if (l - f + 1 == cnt) {
                    for (int j = f; j <= l; j++) {
                        q.push({i, j});
                    }
                }
            }
        }

        q.push({n - 1, 0});
        q.push({0, m - 1});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            ans.push_back({x, y});
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx * dy == 0 && x + dx < n && y + dy < m && x + dx >= 0 && y + dy >= 0) {
                        if (heights[x + dx][y + dy] >= heights[x][y] && !vis[x + dx][y + dy]) {
                            q.push({x + dx, y + dy});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
