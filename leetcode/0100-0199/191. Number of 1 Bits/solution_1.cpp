// Approach: GCC's builtins.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};