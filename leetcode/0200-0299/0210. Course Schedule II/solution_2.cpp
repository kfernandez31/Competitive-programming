// Approach: Kahn's algorithm.
// TC: O(n+m)
// SC: O(n)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            ++indeg[a];
        }
      
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) 
            if (indeg[i] == 0)
                q.push(i);

        vector<int> ans(numCourses);
        int i = -1;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            ans[++i] = v;
            for (int u : graph[v]) 
                if (--indeg[u] == 0)
                    q.push(u);
        }
        return i == numCourses - 1 ? ans : vector<int>();
    }
};