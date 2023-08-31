// Approach: Jump the farthest you can. If a point can't be reached, then the end can't either.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0, n = nums.size();
        for (int i = 0; i < n && i <= far; ++i) 
            far = max(far, i + nums[i]);
        return n - 1 <= far;
    }
};