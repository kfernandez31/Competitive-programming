// Approach: Manacher's algorithm.
// TC: O(n)
// SC: O(n)
class Solution {
    vector<int> manacher_odd(string& s) {
        int n = s.size();
        s = '$' + s + '^';
        vector<int> rad(n + 2);
        int l = 1, r = 1;
        for (int i = 1; i <= n; ++i) {
            rad[i] = min(r - i, rad[l + (r - i)]);
            while (s[i - rad[i]] == s[i + rad[i]])
                ++rad[i];
            if (r < i + rad[i])
                l = i - rad[i], r = i + rad[i];
        }
        return vector<int>(begin(rad) + 1, end(rad) - 1);
    }

    vector<int> manacher(string& s) {
        string t = "#";
        for (char c : s) 
            t += c, t += "#";
        return manacher_odd(t);
    }
public:
    string longestPalindrome(string& s) {
        auto rad = manacher(s);
        
        int ans_start = 0, ans_len = 0;
        for (int i = 1; i < rad.size() - 1; ++i) {
            int len = rad[i] - 1;
            if (ans_len < len) {
                ans_len   = len;
                ans_start = (i - len) / 2; 
                // account for the hashes, which make up around half of the substring. 
                // If there's one more, it means that the best match is before the hash, 
                // and the floor division will take care of this (bring the index back).
            }
        }

        return s.substr(ans_start, ans_len);
    }
};