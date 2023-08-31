// Approach: Sliding window & update the result when pushing the tail.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n   = nums.size();
        int sum = 0, ans = n + 1;
        int tail = 0, head = -1;
        while (head < n) {
            if (sum < target) {
                if (++head < n)
                    sum += nums[head];
            } else {
                ans  = min(ans, head - tail + 1);
                sum -= nums[tail++];
            }
        }

        return ans == n + 1 ? 0 : ans;
    }
};