// Approach: Brute force - try all pairs.
// TC: O(m+n^2)
// SC: O(2n) = O(n)
class Solution {
    static const int maxN = 100;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& edges) {
        unordered_set<int> adj[maxN + 1];
        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                if (i != j) 
                    ans = max(ans, (int)(adj[i].size() + adj[j].size() - (adj[i].contains(j))));
        return ans;
    }
};