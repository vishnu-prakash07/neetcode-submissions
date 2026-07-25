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
        if (intervals.empty())
            return 0;
        
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){
            return a.start < b.start;
        });
        
        priority_queue<int,vector<int>,greater<int>> ans;
        ans.push(intervals[0].end);
        for (int i=1;i<n;i++){
            if (intervals[i].start >= ans.top())
                ans.pop();

            ans.push(intervals[i].end);
        }
        return ans.size();
    }
};
