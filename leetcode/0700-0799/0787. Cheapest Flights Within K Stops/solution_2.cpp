// Approach: BFS.
// TC: O(n+km)
// SC: O(m)
class Solution {
    using pii = pair<int, int>;
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<pii> graph[n];
        for (auto& e : edges)
            graph[e[0]].push_back({e[2], e[1]});
            
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pii> q({0, src});
        while (!q.empty() && k-- >= 0) {
            int sz = q.size();
            while (sz--) {
                auto& [d, v] = q.front(); q.pop();

                for (auto& [w, u] : graph[v]) {
                    if (d + w < dist[u]) {
                        dist[u] = d + w;
                        q.push({d + w, u});
                    }
                } 
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};