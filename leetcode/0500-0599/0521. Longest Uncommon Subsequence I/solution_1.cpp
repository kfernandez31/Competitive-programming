// Approach: The answer is either none, or the longer of the words.
// TC: O(m+n)
// SC: O(1)
class Solution {
public:
    int findLUSlength(string& a, string& b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};