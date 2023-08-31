// Approach: Long addition.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int getSum(int x, int y) {
        bool carry = 0;
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            bool bx = x & (1 << i);
            bool by = y & (1 << i);
            bool sum = bx ^ by ^ carry;
            ans |= sum << i;
            // carry = (bx & by) | (bx & carry) | (by & carry); // at least two operands must be 1
            carry = (bx & by) | carry & (bx | by);
        }
        return ans;
    }
};