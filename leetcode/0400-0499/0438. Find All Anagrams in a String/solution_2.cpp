// Approach: Like solution #1, but more clever.
// TC: O(n+m)
// SC: O(k), k - alphabet size
class Solution {
    static const int ALPHABET_LEN = 26;
    inline int ctoi(const char c) { return c - 'a'; }
public:
    vector<int> findAnagrams(string& s, string& p) {
        int m = s.size(), n = p.size();
        if (m < n)
            return {};

        int count = 0, freq[ALPHABET_LEN] = {};
        for (char c : p)
            if (++freq[ctoi(c)] == 1)
                ++count;

        int r = 0; 
        while (r < n - 1) 
            if (--freq[ctoi(s[r++])] == 0)
                --count;
        
        vector<int> ans;
        while (r < m) {
            if (--freq[ctoi(s[r])] == 0)
                --count;

            int l = r - n + 1;
            if (count == 0)
                ans.push_back(l);

            if (++freq[ctoi(s[l])] == 1)
                ++count;
            ++r;
        }
        return ans;
    }
};