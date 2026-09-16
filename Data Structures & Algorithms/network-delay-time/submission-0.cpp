class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &val : times)
            adj[val[0]].push_back({val[1],val[2]});
        vector<int> time(n+1,INT_MAX);
        time[0] = INT_MIN;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        time[k] = 0;
        pq.push({0 , k});
        while (!pq.empty()){
            auto [t , u] = pq.top();
            pq.pop();

            if ( t > time[u] )
                continue;
            
            for (auto &[v , addOn] : adj[u]){
                if (addOn + t < time[v]){
                    time[v] = addOn + t;
                    pq.push({time[v] , v});
                }
            }
        }
        int ans = *max_element(time.begin(),time.end());
        
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
