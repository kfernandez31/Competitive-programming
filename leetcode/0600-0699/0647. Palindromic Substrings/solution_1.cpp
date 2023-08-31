// Approach: Consider each value or pair of values as the center of a palindrome and expand it outwards.
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int countSubstrings(string& s) {
        int n = s.size(), ans = 0;

        auto expand = [&](int l, int r) {
            while (0 <= l && r < n && s[l] == s[r]) {
                --l, ++r;
                ++ans;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);     // odd length
            expand(i, i + 1); // even length
        }
        return ans;
    }
};