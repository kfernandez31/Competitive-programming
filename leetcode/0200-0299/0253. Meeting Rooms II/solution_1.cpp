// Approach: Consider each interval as two time points, each one affecting the local result.
// TC: O(nlogn)
// SC: O(2n) = O(n)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> events;
        for (auto& interval : intervals) {
            events.push_back({interval.start, +1});
            events.push_back({interval.end,   -1});
        }

        sort(events.begin(), events.end());
        int cur = 0, ans = 0;
        for (auto& event : events) {
            cur += event.second;
            ans  = max(ans, cur);
        }
        return ans;
    }
};