class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for (auto &c : prerequisites){
            int u = c[0];
            int v = c[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i=0;i<n;i++){
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            ans.push_back(u);
            for (int v : adj[u]){
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        if (count == n)
            return ans;
        return {};
    }
};
