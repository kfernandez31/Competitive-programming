// Approach: Put the values into buckets, then compute a suffix sum. If it exceeds k, then you have your answer.
// TC: O(n+r), r - range of nums
// SC: O(r)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int RANGE = 1e4;
        int bucket[2 * RANGE + 1] = {};
        for (int num : nums)
            ++bucket[num + RANGE];
        for (int i = 2 * RANGE - 1; i >= 0; --i) {
            bucket[i] += bucket[i + 1];
            if (bucket[i] >= k)
                return i - RANGE;
        }
        return -1;
    }
};