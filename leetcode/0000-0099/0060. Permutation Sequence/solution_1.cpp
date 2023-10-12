// Approach: STL.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        for (int i = 0; i < n; ++i)
            ans += '0' + i + 1;
        for (int i = 0; i < k - 1; ++i)
            next_permutation(ans.begin(),ans.end());
        return ans;
    }
};