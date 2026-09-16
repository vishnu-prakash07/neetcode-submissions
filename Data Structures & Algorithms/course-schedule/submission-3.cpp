class Solution {
public:
    bool dfs(int u,vector<vector<int>> &adj,vector<int>& visited,vector<int>& pathVisited){
        visited[u] = 1;
        pathVisited[u] = 1;
        for (int v : adj[u]){
            if (!visited[v]){
                if (dfs(v,adj,visited,pathVisited))
                    return true;
            }
            else if(pathVisited[v] == 1)
                return true;
        }
        pathVisited[u] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto &c : prerequisites){
            int u = c[0];
            int v = c[1];
            adj[v].push_back(u);
        }
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        for (int i=0;i<n;i++){
            if (!visited[i]){
                if (dfs(i,adj,visited,pathVisited))
                    return false;//cycle detection in directed graph!
            }
        }
        return true;
    }
};
