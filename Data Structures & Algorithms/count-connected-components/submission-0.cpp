class Solution {
public:

    void dfs(int u,vector<vector<int>> &adj,vector<int>& visited){
        visited[u] = 1;
        for (int v : adj[u]){
            if (!visited[v])
                dfs(v,adj,visited);
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for (auto &c : edges){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=0;i<n;i++){
            if (!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }

        return count;
    }
};
