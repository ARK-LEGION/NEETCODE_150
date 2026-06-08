class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int> ind(n);
        queue<int> q;
        for (auto u:prerequisites){
            adj[u[1]].push_back(u[0]);
            ind[u[0]]++;
        }
        for (int i=0;i<n; i++){
            if (ind[i]==0) q.push(i);
        }
        int len=0;
        vector<int> ans;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            len++;
            for (auto u:adj[node]){
                ind[u]--;
                if (ind[u]==0) q.push(u);
            }
        }
        if (len!=n) return {};
        return ans;
    }
};
