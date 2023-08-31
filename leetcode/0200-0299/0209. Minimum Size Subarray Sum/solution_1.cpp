// Approach: Compute prefix sums, then for each subarray start, find the closest end for which its sum is greater or equalt to the target.
// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1; i < n; ++i)
            pref[i] = pref[i - 1] + nums[i];
        
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            auto l = pref.begin() + i;
            auto r = lower_bound(l, pref.end(), target + *l - nums[i]); // just rearrange the following expression: pref[j] - pref[i] + nums[i] >= target
            if (r == pref.end())
                break;
            else
                ans = min(ans, int(r - l + 1));
        }

        return ans == n + 1 ? 0 : ans;
    }
};