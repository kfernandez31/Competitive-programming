// Approach: Check with connectivity and back-edges using DFS.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n);

        function<bool(int, int)> dfs = [&](int cur, int par) {
            visited[cur] = true;
            for (int next : graph[cur]) {
                if (visited[next]) {
                    if (next != par)
                        return true; // found a back edge
                } else if (dfs(next, cur))
                    return true;
            }
            return false;
        };

        if (dfs(0, 0))
            return false;

        for (bool v : visited) // check for connectivity
            if (!v)
                return false;
        return true;
    }
};