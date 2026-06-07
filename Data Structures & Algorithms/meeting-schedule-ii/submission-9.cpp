/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n==0) return 0;
        sort(intervals.begin(), intervals.end(),[&] (Interval x, Interval y){
            return x.end<y.end;
        });
        
        int ans=1;
        int j=0;
        multiset<int> ms;
        ms.insert(intervals[0].end);
        for (int i=1; i<n; i++){
            auto it = ms.upper_bound(intervals[i].start);
            if(it==ms.begin()){
                ans++;
                ms.insert(intervals[i].end);
            }
            else {
                it--;
                ms.erase(it);
                ms.insert(intervals[i].end);
            }
        }
        return ans;
    }
};
