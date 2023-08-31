// Approach: Like solution #1, but in-place.
// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;
        for (int j = 1; j < intervals.size(); ++j) {
            auto& a = intervals[i];
            auto& b = intervals[j];
            if (a[1] < b[0])
                intervals[++i] = b;
            else
                intervals[i] = {min(a[0], b[0]), max(a[1], b[1])};
        }
        intervals.erase(intervals.begin() + i + 1, intervals.end());
        return intervals;
    }
};