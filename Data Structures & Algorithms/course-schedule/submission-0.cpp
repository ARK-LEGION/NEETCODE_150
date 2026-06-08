class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int> ind(n);
        queue<int> q;
        for (auto u:prerequisites){
            adj[u[0]].push_back(u[1]);
            ind[u[1]]++;
        }
        for (int i=0;i<n; i++){
            if (ind[i]==0) q.push(i);
        }
        int len=0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            len++;
            for (auto u:adj[node]){
                ind[u]--;
                if (ind[u]==0) q.push(u);
            }
        }
        return (len==n);
    }
};
