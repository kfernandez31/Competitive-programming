// Approach: Check if any two adjacent intervals overlaps.
// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start || (a.start == b.start && a.end < b.end);
        });
        for (int i = 1; i < intervals.size(); ++i) {
            auto& a = intervals[i - 1];
            auto& b = intervals[i];
            if (b.start < a.end)
                return false;
        }
        return true;
    }
};