// Approach: Prim's algorithm.
// TC: O(n^2)
// SC: O(n^2)
class Solution {
    inline int manhattan(vector<vector<int>>& p, int i, int j) {
        return abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size(), ans = 0;

        vector<bool> visited(n);
        
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});

        for (int mst_size = 0; mst_size < n;) {
            auto& [d, i] = pq.top(); pq.pop();
            if (visited[i])
                continue;
            ++mst_size;
            ans += -d;
            visited[i] = true;
            for (int j = 0; j < n; ++j) 
                if (!visited[j]) 
                    pq.push({-manhattan(p, i, j), j});   
        }
        return ans;
    }
};