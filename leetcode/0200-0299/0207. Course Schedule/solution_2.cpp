// Approach: Kahn's algorithm..
// TC: O(n+m)
// SC: O(n)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }
      
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) 
            if (indegree[i] == 0)
                q.push(i);

        int nodes_processed = 0;
        while (!q.empty()) {
            ++nodes_processed;
            int v = q.front(); q.pop();
            for (int u : graph[v]) 
                if (--indegree[u] == 0)
                    q.push(u);
        }
        return nodes_processed == numCourses;
    }  
};