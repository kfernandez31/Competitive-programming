// Approach: Check if n is positive and has only bit set.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};