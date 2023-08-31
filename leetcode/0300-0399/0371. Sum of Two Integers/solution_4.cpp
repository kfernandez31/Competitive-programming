// Approach: Interleavings of ANDs and XORs, but more concise.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};