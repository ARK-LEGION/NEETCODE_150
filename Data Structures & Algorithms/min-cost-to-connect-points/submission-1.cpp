class DisjointSet {
   private:
    vector<int> parent;
    vector<int> size;

   public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int ulp_par(int u) {
        if (u == parent[u]) return u;
        return parent[u] = ulp_par(parent[u]);
    }
    void ubs(int u, int v) {
        int ulp_u = ulp_par(u);
        int ulp_v = ulp_par(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        vector<vector<int>> a;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                a.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),
                             i, j});
            }
        }
        sort(a.begin(), a.end());
        DisjointSet DS(n);
        n = a.size();
        
        for (int i = 0; i < n; i++) {
            if (DS.ulp_par(a[i][1]) != DS.ulp_par(a[i][2])) {
                DS.ubs(a[i][1], a[i][2]);
                ans += a[i][0];
            }
        }
        return ans;
    }
};
