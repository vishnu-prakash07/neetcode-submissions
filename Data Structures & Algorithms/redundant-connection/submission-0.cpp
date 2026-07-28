class Solution {
public:

    int findParent(int node,vector<int>& parent){
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void unionSet(int u,int v,vector<int>& parent,vector<int>& size){
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
        vector<int> ans(2);
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> size(n+1,1);

        for (int i=1;i<=n;i++)
            parent[i] = i;

        for (auto edge : edges){
            if (findParent(edge[0],parent) == findParent(edge[1],parent)){
                ans[0] = edge[0];
                ans[1] = edge[1];
            }
            else
                unionSet(edge[0],edge[1],parent,size);
        }
        return ans;
    }
};
