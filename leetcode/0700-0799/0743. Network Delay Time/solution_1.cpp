// Approach: Dijkstra.
// TC: O(n+mlogm)
// SC: O(n+m)
class Solution {
    using pii = pair<int, int>;
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pii>> graph(n + 1);
        for (auto& e : edges)
            graph[e[0]].push_back({e[2], e[1]});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pii> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto& [d, u] = pq.top(); pq.pop();
            if (dist[u] < -d)
                continue;
            for (auto& [w, v] : graph[u]) {
                if (-d + w < dist[v]) {
                    dist[v] = -d + w;
                    pq.push({-dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) // the graph should be strongly connected
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};