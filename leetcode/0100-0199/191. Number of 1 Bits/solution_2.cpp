// Approach: Compare each bit with 1.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
            ans += (n >> i & 1);
        return ans;
    }
};