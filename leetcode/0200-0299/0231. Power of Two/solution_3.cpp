// Approach: Like solution #1.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n >> 31 == 0) && __builtin_popcount(n) == 1;
    }
};