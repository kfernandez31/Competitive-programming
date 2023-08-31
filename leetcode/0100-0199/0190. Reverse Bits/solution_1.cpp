// Approach: Straightforward.
// TC: O(logn)
// SC: O(logn)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 31; i >= 0; --i, n >>= 1) {
            uint32_t shifted_lsb = (n & 1) << i;
            ans |= shifted_lsb;
        }
        return ans;
    }
};