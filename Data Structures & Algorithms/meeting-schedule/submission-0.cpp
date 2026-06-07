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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n  = intervals.size();
        sort(intervals.begin(),intervals.end(),[&](Interval a, Interval b){
            return a.start < b.start;
        });
        int prev=-1;
        for (int i=0; i<n; i++){
            if (intervals[i].start<prev) return false;
            prev=intervals[i].end;
        }
        return true;
    }
};
