class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> pq;
        for (int i=0; i<points.size(); i++){
            double d = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            if (pq.size()<k){
                pq.push({d,points[i]});
            }
            else {
                if (d < pq.top().first){
                    pq.pop();
                    pq.push({d,points[i]});
                }
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
