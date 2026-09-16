class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &val : flights){
            int u,v,c;
            u = val[0];
            v = val[1];
            c = val[2];
            adj[u].push_back({v,c});
        }
        int answer = INT_MAX;
        //cost,node,stops
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(n,vector<int> (k+2,INT_MAX));

        dist[src][0] = 0;
        pq.push({0,src,0});
        while (!pq.empty()){
            auto [cost,u,stops] = pq.top();
            pq.pop();

            if (u == dst){
                answer = min(answer,cost);
                continue;
            }

            if ( stops == k+1)
                continue;
            
            for (auto &[v , price] : adj[u]){
                int newCost = cost + price;
                int newStops = stops + 1;
                if (newCost < dist[v][newStops]){
                    dist[v][newStops] = newCost;
                    pq.push({newCost , v , newStops});
                }
            }
        }

        if (answer == INT_MAX)
            return -1;
        
        return answer;
    }
};
