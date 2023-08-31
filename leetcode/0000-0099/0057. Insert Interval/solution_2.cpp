// Approach: Like solution #1, but using STL.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto l = lower_bound(intervals.begin(), intervals.end(), newInterval, [](auto& e, auto& t) {
            return e[1] < t[0];
        });

        auto r = lower_bound(intervals.begin(), intervals.end(), newInterval, [](auto& e, auto& t) {
            return e[0] <= t[1];
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