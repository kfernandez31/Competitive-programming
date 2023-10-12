// Approach: Whenever encountering a pair of lesser-greater digits, treat it as the special case, otherwise just parse one digit.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int romanToInt(string& s) {
        unordered_map<char, int> m = {
            {0, 0},
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) 
            if (m[s[i]] >= m[s[i + 1]]) 
                ans += m[s[i]];
            else 
                ans += m[s[i + 1]] - m[s[i++]];
        return ans;
    }
};