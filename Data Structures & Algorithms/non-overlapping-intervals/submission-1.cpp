class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n  = intervals.size();
        sort(intervals.begin(), intervals.end());
        int prev=INT_MIN;
        int cnt=0;
        for (int i=0; i<n; i++){
            if (intervals[i][0]>=prev){
                cnt++;
                prev=intervals[i][1];
            }
            else{
                if (intervals[i][1]<prev) prev=intervals[i][1];
            }
        }
        return n-cnt;
    }
};
