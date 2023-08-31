// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i = 0; i < 32 && n; ++i, n >>= 1)
            ans[i & 1] += n & 1;
        return ans;
    }
};