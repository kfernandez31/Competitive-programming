// Approach: Prim's algorithm for complete graphs.
// TC: O(n^2)
// SC: O(n)
class Solution {
    inline int manhattan(vector<vector<int>>& p, int i, int j) {
        return abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;
        
        vector<int> dist(n, INT_MAX - 1);

        for (int mst_size = 0, i = 0; ++mst_size < n;) {
            dist[i] = INT_MAX; // mark as visited
            
            int next = i;
            for (int j = 0; j < n; ++j) {
                if (dist[j] != INT_MAX) {
                    dist[j] = min(dist[j], manhattan(p, i, j));
                    if (dist[j] < dist[next])
                        next = j;
                }
            }
            ans += dist[next];
            i    = next;
        }

        return ans;
    }
};