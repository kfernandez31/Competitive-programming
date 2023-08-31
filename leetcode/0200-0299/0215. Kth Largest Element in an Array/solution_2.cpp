// Approach: Prefix sum over buckets.
// TC: O(r+n), r - range of nums
// SC: O(r)
class Solution {
    static constexpr int RANGE = 1e4;
public:
    int findKthLargest(vector<int>& nums, int k) {
        int bkt[2 * RANGE + 1] = {};
        for (int num : nums)
            ++bkt[num + RANGE];
        for (int i = 2 * RANGE - 1; i >= 0; --i) {
            bkt[i] += bkt[i + 1];
            if (bkt[i] >= k)
                return i - RANGE;
        }
        return -1;
    }
};