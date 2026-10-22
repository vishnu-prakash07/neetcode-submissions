class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<pair<int,int>> event;
        for (auto& trip : trips){
            int passenger = trip[0];
            int start = trip[1];
            int end = trip[2];

            event.push_back({start,passenger});
            event.push_back({end,-passenger});
        }

        sort(event.begin(),event.end());
        int curr = 0;
        for (auto& val : event){
            curr += val.second;
            if (curr > capacity)
                return false;
        }
        return true;
    }
};