class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<int> v;
        for (int i=0; i<n; i++){
            v.push_back(intervals[i][0]);
            v.push_back(intervals[i][1]);
        }
        int i1 = lower_bound(v.begin(), v.end(), newInterval[0]) - v.begin();
        v.insert(v.begin()+i1, newInterval[0]);
        int i2 = upper_bound(v.begin(), v.end(), newInterval[1]) - v.begin();
        v.insert(v.begin()+i2, newInterval[1]);

        vector<vector<int>> ans;
        if (i1%2==1) i1--;
        if ((v.size()-1-i2)%2==1) i2++;
        for (int i=0; i<i1; i+=2){
            ans.push_back({v[i], v[i+1]});
        }
        if (i2<v.size())ans.push_back({v[i1],v[i2]});
        else ans.push_back({v[i1],v[i2-1]});
        
        for (int i=i2+1; i<v.size(); i+=2) ans.push_back({v[i], v[i+1]});
        for (auto u:v) cout<<u<<" ";
        return ans;
    }
};
