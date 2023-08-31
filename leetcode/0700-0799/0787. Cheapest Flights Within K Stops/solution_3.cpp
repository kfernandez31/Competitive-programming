// Approach: Bellman-Ford.
// TC: O(n+km)
// SC: O(2n) = O(n)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));
        dp[0][src] = dp[1][src] = 0;
        for (int i = 0; i <= k; ++i) {
            for (auto& e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dp[0][u] != INT_MAX)
                    dp[1][v] = min(dp[1][v], dp[0][u] + w);
            }
            swap(dp[0], dp[1]);
        }
        return dp[0][dst] == INT_MAX ? -1 : dp[0][dst];
    }
};