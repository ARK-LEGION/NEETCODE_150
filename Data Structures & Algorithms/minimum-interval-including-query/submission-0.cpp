class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<vector<int>> events;
        for (int i=0; i<n; i++){
            events.push_back({intervals[i][0],0,intervals[i][1]-intervals[i][0]+1, i});
            events.push_back({intervals[i][1],2, i});
        }
        for (int i=0; i<m; i++){
            events.push_back({queries[i], 1, i});
        }
        sort(events.begin(), events.end());
        vector<int> ans(m,-1);
        vector<int> inactive(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for (auto event:events){
            if (event[1]==0){
                pq.push({event[2],event[3]});
            }
            else if (event[1]==2){
                inactive[event[2]]=1;
            }
            else{
                while (!pq.empty() && inactive[pq.top().second]==1) pq.pop();
                if (!pq.empty()) ans[event[2]]=pq.top().first;
            }
        }
        return ans;
    }
};
