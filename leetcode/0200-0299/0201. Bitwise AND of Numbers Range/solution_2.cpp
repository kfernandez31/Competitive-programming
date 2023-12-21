// Approach: Cut down bits until we have a common prefix, which is the answer.
// TC: O(log(r-l))
// SC: O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int suf_len = 0;
        while (left != right) {
            left  >>= 1; 
            right >>= 1;
            ++suf_len;
        }
        return left << suf_len;
    }
};