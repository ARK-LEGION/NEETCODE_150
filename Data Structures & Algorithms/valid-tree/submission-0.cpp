class DisjointSet{
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n){
        parent.resize(n,0);
        size.resize(n,1);
        for (int i=0; i<n; i++) parent[i]=i;
    }
    int ulp_par(int node){
        if (parent[node]==node) return node;
        return parent[node] = ulp_par(parent[node]);
    }
    void ubs(int u,int v){
        int pu = ulp_par(u);
        int pv = ulp_par(v);
        if (pu==pv) return;
        if (size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size()!=n-1) return false;
        DisjointSet DS(n);
        for (int i=0; i<n-1; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if (DS.ulp_par(u)==DS.ulp_par(v)) return false;
            DS.ubs(u,v);
        }
        return true;
    }
};
