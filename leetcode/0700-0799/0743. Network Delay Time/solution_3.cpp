// Approach: BFS.
// TC: O(n+m)
// SC: O(n+m)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& e : edges)
            graph[e[0]].push_back({e[2], e[1]});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        queue<int> q{{k}};
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int v = q.front(); q.pop();
                for (auto& [w, u] : graph[v]) {
                    int d = dist[v] + w;
                    if (d < dist[u]) {
                        dist[u] = d;
                        q.push(u);
                    }
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};