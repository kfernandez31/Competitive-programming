// Approach: For the given start, find an end for which s[start, end] is a palindrome, and then recurse.
// TC: O(n^2 * 2^n)
// SC: O(n)
class Solution {
    inline bool is_palindrome(string& s, int l, int r) {
        while (l < r) 
            if (s[l++] != s[r--]) 
                return false;
        return true;
    }
public:
    vector<vector<string>> partition(string& s) {
        vector<vector<string>> ans;
        vector<string> acc;
        int n = s.size();

        function<void(int)> bt = [&](int start) {
            if (start == n) {
                ans.push_back(acc);
                return;
            }

            for (int end = start; end < n; ++end) {
                if (is_palindrome(s, start, end)) {
                    acc.push_back(s.substr(start, end - start + 1));
                    bt(end + 1);
                    acc.pop_back();
                }
            }
        };

        bt(0);
        return ans;
    }
};