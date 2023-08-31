// Approach: Consider each value or pair of values as the center of a palindrome and expand it outwards.
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    string longestPalindrome(string& s) {
        int n = s.size(), ans_i = 0, ans_len = 1;

        auto expand = [&](int l, int r) {
            while (0 <= l - 1 && r + 1 < n && s[l - 1] == s[r + 1]) 
                --l, ++r;
            if (r - l + 1 > ans_len) 
                ans_len = r - l + 1, ans_i = l;
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);         // odd length
            if (i + 1 < n && s[i] == s[i + 1]) 
                expand(i, i + 1); // even length
        }
        return s.substr(ans_i, ans_len);
    }
};