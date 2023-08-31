// Approach: One mask. If the strings differ at only one position, then the mask will have only one bit set.
// TC: O(m+n)
// SC: O(k), k - alphabet size
class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        int mask = 0;
        for (char c : s)
            mask ^= 1 << c - 'a';
        for (char c : t)
            mask ^= 1 << c - 'a';

        char i = 0;
        while ((mask & (1 << i)) == 0) 
            ++i;
        return i + 'a';
    }
    
};
