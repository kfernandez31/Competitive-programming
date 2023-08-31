// Approach: On overlap, keep the interval that ends earlier.
// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    // Solution 1: greedy. On overlap, remove the latter one. O(nlogn) TC, O(1) SC
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int nremoved = 0, last = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            auto& a = intervals[last];
            auto& b = intervals[i];
            if (a[1] <= b[0]) // no overlap, advance last
                last = i;
            else {
                ++nremoved;
                if (b[1] < a[1]) { // keep b
                    // a0-----------a1
                    //   b0-----b1
                    last = i;
                }
                // keep a
                // a0-----a1
                //     b0--------b1         
            }
        }
    
        return nremoved;
    }
};