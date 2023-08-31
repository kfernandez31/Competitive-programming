// Approach: Dial's algorithm (generalized 0-1 BFS).
// TC: O(w*n+m), w - max edge weight
// SC: O(w+n+m)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        int max_w = 0;
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& e : edges) {
            max_w = max(max_w, e[2]);
            graph[e[0]].push_back({e[2], e[1]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
``
        int nbuckets = max_w * n + 1;
        unordered_set<int> bkt[nbuckets];
        bkt[0].insert(k);

        while (true) {
            int d = -1; // d will mark the first non-empty bucket
            for (int i = 0; i < nbuckets && d == -1; ++i) 
                if (!bkt[i].empty()) 
                    d = i;
            if (d == -1)
                break;

            int u = *bkt[d].begin(); bkt[d].erase(u);

            for (auto& [w, v] : graph[u]) {
                int new_d = d + w;
                if (new_d < dist[v]) {
                    if (dist[v] != INT_MAX) 
                        bkt[dist[v]].erase(v);
                    bkt[new_d].insert(v);
                    dist[v] = new_d;
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