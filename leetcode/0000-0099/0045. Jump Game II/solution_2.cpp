// Approach: Like solution #1, but count the segments after you create them.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i)
            nums[i] = max(nums[i - 1], i + nums[i]);
        int ans = 0;
        for (int i = 0; i < n - 1; i = nums[i])
            ++ans;
        return ans;
    }
};
