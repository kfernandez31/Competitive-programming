// Approach: Iterate through intervals, maintaining a set of the remaining queries to fulfill.
// TC: O(nlogn+mlogm)
// SC: O(m)
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ivs, vector<int>& queries) {
        int m = queries.size();

        sort(ivs.begin(), ivs.end(), [](auto& a, auto& b) {  return a[1] - a[0] < b[1] - b[0]; });

        set<pair<int, int>> qs;
        for (int i = 0; i < m; ++i)
            qs.insert({queries[i], i});

        vector<int> ans(m, -1);

        for (auto& iv : ivs) {
            int l = iv[0], r = iv[1];
            auto q = qs.lower_bound({l, -1}); // binary search for the first query the current interval can answer
            while (q != qs.end() && q->first <= r) { // answer all possible queries
                ans[q->second] = r - l + 1;
                q = qs.erase(q);
            }
        }
        return ans;
    }
};