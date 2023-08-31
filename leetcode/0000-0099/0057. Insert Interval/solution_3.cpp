// Approach: Like solution #2, but more standard.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto l = lower_bound(intervals.begin(), intervals.end(), newInterval, [](auto& e, auto& t) {
            return e[1] < t[0]; // "before l, this holds"
        });

        auto r = upper_bound(intervals.begin(), intervals.end(), newInterval, [](auto& t, auto& e) {
            return t[1] < e[0]; // "from r, this holds"
        });

        if (l == r) 
            intervals.insert(l, newInterval);
        else {
            l->at(0) = min(newInterval[0], l->at(0));
            l->at(1) = max(newInterval[1], prev(r)->at(1));
            intervals.erase(l + 1, r);
        }
        return intervals;
    }
};