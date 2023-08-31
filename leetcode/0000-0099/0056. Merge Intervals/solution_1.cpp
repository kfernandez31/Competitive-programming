// Approach: Straightforward.
// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans = {intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            auto& a = ans.back();
            auto& b = intervals[i];
            if (a[1] < b[0])  // [    ] [    ]
                ans.push_back(b);
            else
                a = {min(a[0], b[0]), max(a[1], b[1])}; // [  [  ] ]
        }
        return ans;
    }
};