// Approach: Topological sort. For each neighboring pair of words, find the index of their mismatch and record the two characters' order. Then perform standard toposort.
// TC: O(nk), k - avg word length
// SC: O(l^2), l - alphabet size
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indeg;
        for (auto& word : words)
            for (char c : word)
                indeg[c] = 0;

        unordered_map<char, unordered_set<char>> adj;
        for (int i = 1; i < words.size(); ++i) {
            string &a = words[i - 1], &b = words[i];

            int shorter_len;
            if (a.size() < b.size())
                shorter_len = a.size();
            else {
                shorter_len = b.size();
                if (a.find(b) == 0)
                    return "";
            }
            
            int j = 0;
            while (j < shorter_len && a[j] == b[j]) 
                ++j;
            
            if (j < shorter_len) {
                adj[a[j]].insert(b[j]);
                ++indeg[b[j]];
            }
        }

        queue<char> q;
        for (auto& [c, deg] : indeg) 
            if (deg == 0) 
                q.push(c);

        string order;
        while (!q.empty()) {
            char v = q.front(); q.pop();
            order += v;
            for (char u : adj[v]) 
                if (--indeg[u] == 0)
                    q.push(u);
        }

        return order.size() == adj.size() ? order : "";
    }
};