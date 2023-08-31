// Approach: Iterate through queries, maintaining currently open intervals on a minheap with regard to their size.
// TC: O(nlogn+mlogm)
// SC: O(n+m)
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ivs, vector<int>& queries) {
        int m = queries.size();

        sort(ivs.begin(), ivs.end());

        set<pair<int, int>> qs;
        for (int i = 0; i < m; ++i)
            qs.insert({queries[i], i});

        vector<int> ans(m);
        auto iv = ivs.begin();
        priority_queue<pair<int, int>> pq;
        
        for (auto& [q, i] : qs) {
            // push new, open intervals
            while (iv != ivs.end()) {
                int l = iv->at(0), r = iv->at(1);
                if (q < l)
                    break;
                pq.push({-(r - l + 1), r});
                ++iv;
            }
            // pop old, closed intervals
            while (!pq.empty() && pq.top().second < q)
                pq.pop();

            ans[i] = pq.empty() ? -1 : -pq.top().first; 
        }

        return ans;
    }
};