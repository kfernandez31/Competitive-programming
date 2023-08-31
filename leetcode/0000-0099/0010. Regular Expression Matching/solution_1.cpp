// Approach: STL. Too slow to be practical.
// TC: O(?)
// SC: O(?)
class Solution {
public:
    bool isMatch(string& s, string& p) {
        return regex_match(s, regex(p));
    }
};