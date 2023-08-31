// Approach: Like solution #1, just carry out the merge operation explicitly.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3);
        for (auto& t : triplets) {
            if (target[0] < t[0] || target[1] < t[1] || target[2] < t[2])
                continue;
            ans[0] = max(ans[0], t[0]);
            ans[1] = max(ans[1], t[1]);
            ans[2] = max(ans[2], t[2]);
        }
        return ans == target;
    }
};