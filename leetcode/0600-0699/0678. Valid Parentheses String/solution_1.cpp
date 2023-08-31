// Approach: First treat wildcards as '(', then as ').
// TC: O(2n) = O(n)
// SC: O(1)
class Solution {
public:
    bool checkValidString(string& s) {
        int n = s.size();

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '*')
                ++cnt;
            else if (cnt > 0)
                --cnt;
            else
                return false;
        }

        cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || s[i] == '*')
                ++cnt;
            else if (cnt > 0)
                --cnt;
            else
                return false;
        }

        return true;
    }
};