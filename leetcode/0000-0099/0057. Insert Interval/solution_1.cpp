// Approach: Search for the first (l) and last (r - 1) intervals which overlap with the new one. Merge them, and erase everything between them.
// TC: O(n)
// SC: O(1)
class Solution {
    int binsearch(int lo, int hi, function<bool(int)> pred) {
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (!pred(mid)) 
                lo = mid;
            else 
                hi = mid;
        }
        return hi;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //    l0----------l1   r0----------r1
        //          n0++++++++++++++n1
        int n = intervals.size();
        int l = binsearch(-1, n,    [&](int i) { return intervals[i][1] >= newInterval[0]; });
        int r = binsearch(l - 1, n, [&](int i) { return intervals[i][0] >  newInterval[1]; });

        if (l == r)
            intervals.insert(intervals.begin() + l, newInterval);
        else {
            intervals[l][0] = min(newInterval[0], intervals[l][0]);
            intervals[l][1] = max(newInterval[1], intervals[r - 1][1]);
            intervals.erase(intervals.begin() + l + 1, intervals.begin() + r);
        }
        return intervals;
    }
};