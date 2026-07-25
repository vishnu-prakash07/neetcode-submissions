class Solution {
public:

    void validCheck(vector<vector<int>>& adj,vector<bool>& visited){
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto &neighbor : adj[node]){
                if (!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        int edge = edges.size();
        if ( edge != n-1)
            return false;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for (int i=0;i<edge;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        validCheck(adj,visited);
        for (int i=0;i<n;i++){
            if (!visited[i])
                return false;
        }
        return true;
    }
};
