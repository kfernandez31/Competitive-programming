// Approach: Run introselect, then take k.
// TC: O(n) average, O(n^2) worst case
// SC: O(logn)
class Solution {
    inline int d(vector<int>& p) { return p[0] * p[0] + p[1] * p[1]; }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& ps, int k) {
        nth_element(ps.begin(), ps.begin() + k, ps.end(), [&](auto& a, auto& b) {
            return d(a) < d(b);
        });
        ps.resize(k);
        return ps;
    }
};