class Solution {
public:
    int evaluateDist(int x,int y){
        return x*x + y*y ;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> distance;
        vector<vector<int>> res;
        for (auto &point : points){
            int x = point[0];
            int y = point[1];
            int dist = evaluateDist(x,y);
            distance.push_back({dist,x,y});
        }
        sort(distance.begin(),distance.end());
        for (int i=0;i<k;i++){
            int x = distance[i][1];
            int y = distance[i][2];
            res.push_back({x,y});
        }
        return res;
    }
};
