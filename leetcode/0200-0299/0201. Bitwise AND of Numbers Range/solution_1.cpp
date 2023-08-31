// Approach: Brute force, but only for a small range with a common prefix.
// TC: O(r-l)
// SC: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0)
            return 0;
        if ((int)log2(left) != (int)log2(right))
            return 0;

        int ans = left;
        for (long i = left; i <= right; ++i) 
            ans &= i;
        return ans;
    }
};