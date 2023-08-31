// Approach: Multi-dimensional Dijkstra.
// TC: O(k+mlogm)
// SC: O(kn+m)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        if (k == 0) { // look up the cheapest edge
            int ans = INT_MAX;
            for (auto& e : edges) 
                if (e[0] == src && e[1] == dst)
                    ans = min(ans, e[2]);
            return ans == INT_MAX ? -1 : ans;
        }

        vector<pair<int, int>> graph[n];
        for (auto& e : edges) 
            graph[e[0]].push_back({e[2], e[1]});

        vector<vector<int>> dist(k + 3, vector<int>(n, INT_MAX));
        dist[1][src] = 0;

        priority_queue<tuple<int, int, int>> pq;
        pq.push({0, src, 1});
        
        while (!pq.empty()) {
            auto& [d, u, cnt] = pq.top(); pq.pop();

            if (-d != dist[cnt][u]) 
                continue;

            for (auto& [w, v] : graph[u]) {
                if (v == dst) {
                    if (cnt + 1 <= k + 2 && -d + w < dist[cnt + 1][v])
                        dist[cnt + 1][v] = -d + w;
                } else if (cnt + 1 <= k + 1 && -d + w < dist[cnt + 1][v]) {
                    dist[cnt + 1][v] = -d + w;
                    pq.push({-dist[cnt + 1][v], v, cnt + 1});
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 2; i <= k + 2; ++i)
            ans = min(ans, dist[i][dst]);
        return ans == INT_MAX ? -1 : ans;
    }
};