// Approach: Hierholzer's algorithm for finding an eulerian path.
// TC: O(mlogm)
// SC: O(m)
class Solution {
    using minheap_t = priority_queue<string, vector<string>, greater<string>>;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, minheap_t> graph;
        for (auto& e : tickets) 
            graph[e[0]].push(e[1]);

        vector<string> ans;
        function<void(string)> dfs = [&](string cur) {
            auto& edges = graph[cur];
            while (!edges.empty()) {
                string next = edges.top(); edges.pop();
                dfs(next);
            }
            ans.push_back(cur);
        };

        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};