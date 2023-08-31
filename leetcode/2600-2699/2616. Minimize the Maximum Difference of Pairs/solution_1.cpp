// Approach: Sort the array, then find the first pair for whom there are p-1 pairs before it whose difference is not greater.
// TC: O(nlogn)
// SC: O(1)
class Solution {
    // greedily count pairs whose difference is not greater than p
     bool can_form_pairs(vector<int>& nums, int diff, int p) {
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt < p;) {
            if (nums[i] - nums[i - 1] <= diff) {
                ++cnt;
                i += 2;
            } else 
                i += 1;
        }
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0)
            return 0;
        
        sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) 
            min_diff = min(min_diff, nums[i] - nums[i - 1]);

        int lo = min_diff - 1, hi = nums.back() - nums.front() + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (!can_form_pairs(nums, mid, p))
                lo = mid;
            else 
                hi = mid;
        }

        return hi;
    }
};