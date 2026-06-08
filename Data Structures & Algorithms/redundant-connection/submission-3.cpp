class DisjointSet{
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,1);
        for(int i=1;i<=n; i++) parent[i]=i;
    }
    int ulp_par(int u){
        if (u==parent[u]) return u;
        return parent[u]=ulp_par(parent[u]);
    }
    void ubs(int u, int v){
        int pu = ulp_par(u);
        int pv = ulp_par(v);
        if (size[pu]<size[pv]){
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        else{
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=0;
        for (int i=0;i<edges.size(); i++){
            n=max(n,max(edges[i][0],edges[i][1]));
        }
        DisjointSet DS(n);
        vector<int> ans={-1,-1};
        for (int i=0; i<edges.size();i++){
            if (DS.ulp_par(edges[i][0])==DS.ulp_par(edges[i][1])){
                ans = edges[i];
            }
            else DS.ubs(edges[i][0], edges[i][1]);
        }
        return ans;
    }
};
