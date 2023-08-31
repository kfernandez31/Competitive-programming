// Approach: Two masks.
// TC: O(m+n)
// SC: O(2k) = O(k), k - alphabet size
class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        int s_bits = 0;
        for (char c : s)
            s_bits ^= 1 << c - 'a';

        int t_bits = 0;
        for (char c : t)
            t_bits ^= 1 << c - 'a';

        int diff = s_bits ^ t_bits;
        
        char i = 0;
        while ((diff & (1 << i)) == 0) 
            ++i;
        return i + 'a';
    }
};
