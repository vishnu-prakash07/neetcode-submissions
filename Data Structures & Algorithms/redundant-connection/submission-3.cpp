class Solution {
public:

    int findParent(int u,vector<int>& parent){
        if (parent[u] == u)
            return parent[u];
        return parent[u] = findParent(parent[u] , parent);
    }

    void unionSet(int u,int v,vector<int>& size,vector<int>& parent){
        int pu = findParent(u,parent);
        int pv = findParent(v,parent);

        if (pu == pv)
            return;
        
        if (size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> size(n+1,1);

        for (int i=1;i<=n;i++)
            parent[i] = i;
        
        for (auto &edge : edges){
            if (findParent(edge[0],parent) == findParent(edge[1],parent))
                return edge;
            else
                unionSet(edge[0],edge[1],size,parent);
        }
        return {};
    }
};
