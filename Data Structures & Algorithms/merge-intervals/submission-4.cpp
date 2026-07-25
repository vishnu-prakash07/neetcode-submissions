class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> checkPoints(1001,0);
        int minStart = 1001;
        int maxEnd = -1;
        vector<bool> startEnd(1001,false);
        for (auto &val : intervals){
            int start = val[0];
            int end = val[1];
            if (start == end)
                startEnd[start] = true;
            minStart = min(start,minStart);
            maxEnd = max(end,maxEnd);
            checkPoints[start] -= 1;
            checkPoints[end] += 1;
        }
        vector<vector<int>> ans;
        int check = 0;
        int start = 1001;
        int end = 1001;
        for (int i=minStart;i<=maxEnd;i++){
            if (checkPoints[i] < 0 && check == 0)
                start = i;
            else if (checkPoints[i] > 0)
                end = i;
            check += checkPoints[i];
            if (check == 0 && checkPoints[i]!= 0)
                ans.push_back({start,end});
            if (check == 0 && startEnd[i] == true && checkPoints[i] == 0)
                ans.push_back({i,i});
        }
        return ans;
    }
};
