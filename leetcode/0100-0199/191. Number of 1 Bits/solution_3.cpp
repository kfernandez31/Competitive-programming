// Approach: A different take at solution #2.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};