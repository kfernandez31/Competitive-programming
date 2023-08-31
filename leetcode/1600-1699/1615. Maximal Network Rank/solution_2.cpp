// Approach: If there is only one vertex with the max, consider it and the second best. If not, try to find at least one unconnected pair.
// TC: O(m+n)
// SC: O(2n) = O(n)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n);
        for (auto& r : roads) 
            ++deg[r[0]], ++deg[r[1]];
        
        int i_max   = max_element(deg.begin(), deg.end()) - deg.begin();
        int cnt_max = count(deg.begin(), deg.end(), deg[i_max]);

        if (cnt_max == 1) {
            vector<unordered_set<int>> adj(n);
            for (auto& r : roads) {
                int a = r[0], b = r[1];
                adj[a].insert(b);
                adj[b].insert(a);
            }

            int ans = -1;
            for (int i = 0; i < n; ++i)
                if (i != i_max)
                    ans = max(ans, deg[i_max] + deg[i] - adj[i].contains(i_max));
            return ans;
        }
        else {
            int edges_connecting_maxs = count_if(roads.begin(), roads.end(), [&](auto& r) {
                return deg[r[0]] == deg[i_max] && deg[r[1]] == deg[i_max];
            });
            // if not all maxs are connected, we can choose the unconnected pair
            return 2 * deg[i_max] - (edges_connecting_maxs == cnt_max * (cnt_max - 1) / 2);
        }        
    }
};
