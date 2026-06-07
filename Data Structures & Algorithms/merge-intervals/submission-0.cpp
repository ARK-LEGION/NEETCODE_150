class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n  = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int i=0;
        vector<vector<int>> ans;
        while(i<n ){
            int j=i;
            int maxi = intervals[j][1];
            while (j<n && intervals[j][0]<=maxi){
                
                maxi=max(maxi,intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0],maxi});
            i=j;
        }
        return ans;
    }
};
