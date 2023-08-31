// Approach: Check if n is a power of two with the bit set at one of the mask's positions.
// TC: O(n)
// SC: O(n)
class Solution {
    static const int mask = 0x55555555;
public:
    bool isPowerOfFour(int n) {
        return (n >> 31 == 0) && (n & (n - 1)) == 0 && (n & mask) != 0;
    }
};