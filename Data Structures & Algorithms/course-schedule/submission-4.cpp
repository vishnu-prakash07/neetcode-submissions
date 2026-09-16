class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for (auto &c : prerequisites){
            int u = c[0];
            int v = c[1];
            adj[v].push_back(u);
            inDegree[u]++;
        }
        queue<int> q;
        for (int i=0;i<n;i++){
            if (inDegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty()){
            int u = q.front();
            q.pop();

            for (int v : adj[u]){
                inDegree[v]--;

                if (inDegree[v] == 0)
                    q.push(v);
            }
            count++;
        }

        return count == numCourses;
    }
};
