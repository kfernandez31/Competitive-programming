// Approach: Cut down bits until we have a common prefix, which is the answer.
// TC: O(log(r-l))
// SC: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int pref_len = 0;
        while (left != right) {
            left  >>= 1; 
            right >>= 1;
            ++pref_len;
        }
        return left << pref_len;
    }
};