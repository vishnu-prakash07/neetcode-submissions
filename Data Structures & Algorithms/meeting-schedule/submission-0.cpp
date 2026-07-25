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
        int n = intervals.size();
        if (!intervals.size())
            return true;
        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){
            return a.start < b.start;
        });
        int prevEnd = intervals[0].end;
        // int prevStart = intervals[0][0];
        for (int i=1;i<n;i++){
            if (intervals[i].start < prevEnd)
                return false;
            prevEnd = intervals[i].end;
        }
        return true;
    }
};
