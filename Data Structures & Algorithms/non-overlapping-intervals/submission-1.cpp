class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b)
        {
            return a[1]<b[1];
        });
        int removals = 0;
        int prevEnd = intervals[0][1];
        int n = intervals.size();
        for (int i=1;i<n;i++){
            if (intervals[i][0] < prevEnd) //to be removed!
                removals++;
            else
                prevEnd = intervals[i][1];
        }
        return removals;
    }
};
