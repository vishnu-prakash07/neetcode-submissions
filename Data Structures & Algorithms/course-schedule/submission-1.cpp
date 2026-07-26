class Solution {
public:

    bool dfs(int i,vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& pathVisited){
        visited[i] = true;
        pathVisited[i] = true;

        for (int node : adj[i]){
            if (!visited[node]){
                if (dfs(node,adj,visited,pathVisited))
                    return true;
            }
            else if (pathVisited[node])
                return true;
        }

        pathVisited[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> pathVisited(numCourses,false);

        vector<vector<int>> adj(numCourses);

        for (auto &x: prerequisites){
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }

        for (int i=0;i<numCourses;i++){
            if (!visited[i])
                if (dfs(i,adj,visited,pathVisited))
                    return false;
        }
        return true;

    }
};
