// Approach: One string increments character frequency, the other decrements it. 
// TC: O(m+n+k), k - alphabet size
// SC: O(k)
class Solution {
    static const int ALPHABET_LEN = 26;
    inline int ctoi(char c) { return c - 'a'; }
public:
    bool isAnagram(string& s, string& t) {
        int cnt[ALPHABET_LEN] = {};
        for (char c : s)
            ++cnt[ctoi(c)];
        for (char c : t) 
            --cnt[ctoi(c)];
        for (int c : cnt)
            if (c != 0)
                return false;
        return true;
    }
};