// Approach: Kernighan's algorithm.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int hammingWeight(uint32_t n) {
       int ans = 0;
       while (n) {
            n &= n - 1;
            ++ans;
        }
        return ans;
    }
};