// Approach: Check if n is a power of two and 1mod3.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n >> 31 == 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};