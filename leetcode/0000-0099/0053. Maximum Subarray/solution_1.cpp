// Approach: Kadane's algorithm.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, cur_sum = 0, cur_max = -1e4 - 1;
        for (int num : nums) {
            cur_sum = max(0, cur_sum + num);
            ans     = max(ans, cur_sum);
            cur_max = max(cur_max, num);
        }
        return ans == 0 ? cur_max : ans;
    }
};