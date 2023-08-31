// Approach: Like solution #1 but more concise.
// TC: O(nlogn)
// SC: O(2n) = O(n)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto& i : intervals) 
            ++m[i.start], --m[i.end];
        
        int ans = 0, cur = 0;
        for (auto& [_, v] : m) {
            cur += v;
            ans  = max(ans, cur);
        }
        return ans;
    }
};