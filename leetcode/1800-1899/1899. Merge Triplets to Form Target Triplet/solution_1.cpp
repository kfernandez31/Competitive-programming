// Approach: Consider only triplets which contribute to the target. Among them, conceptually, pick one which fulfills the first position, the second and the third. If we can fulfill all, then the answer is true.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool ans[3] = {};
        for (auto& t : triplets) {
            if (target[0] < t[0] || target[1] < t[1] || target[2] < t[2])
                continue;
            ans[0] |= t[0] == target[0];
            ans[1] |= t[1] == target[1];
            ans[2] |= t[2] == target[2];
        }
        return ans[0] & ans[1] & ans[2];
    }
};