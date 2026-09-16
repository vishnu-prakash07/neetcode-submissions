class Solution {
public:

    int findParent(int u,vector<int>& parent){
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u],parent);
    }

    void unionSet(int u,int v,vector<int>& parent,vector<int>& size){
        int pu = findParent(u,parent);
        int pv = findParent(v,parent);

        if (pu == pv)
            return;
        if (size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<int,pair<int,int>> p;
        int idx = 0;
        for (auto &c : points){
            int u = c[0];
            int v = c[1];
            p[idx] = {u,v};
            idx++;
        }
        vector<vector<int>> edges;
        idx = 0;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int costX = abs(p[i].first - p[j].first);
                int costY = abs(p[i].second - p[j].second);
                int cost = costX + costY;
                edges.push_back({cost,i,j});
            }
        }
        sort(edges.begin(),edges.end(),[](vector<int> &a,vector<int>& b){
            return a[0] < b[0];
        });
        vector<int> parent(n);
        vector<int> size(n,1);
        for (int i=0;i<n;i++)
            parent[i] = i;
        
        int minCost = 0;
        int edgeCount = 0;
        for (auto &edge : edges){
            int cost = edge[0];
            int u = edge[1];
            int v = edge[2];
            if (findParent(u,parent) != findParent(v,parent)){
                unionSet(u,v,parent,size);
                minCost += cost;
                edgeCount++;
            }
            if (edgeCount == n-1)
                break;
        }
        return minCost;
    }
};
