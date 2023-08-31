// Approach: Sliding window with two passes - first, expand the window to cover m elements, then push both its ends.
// TC: O(n+km), k - alphabet size
// SC: O(k)
class Solution {
    static const int ALPHABET_LEN = 26;
    inline int ctoi(const char c) { return c - 'a'; }
public:
    vector<int> findAnagrams(string& s, string& p) {
        int m = s.size(), n = p.size();
        if (m < n)
            return {};

        int freq[ALPHABET_LEN] = {};
        for (char c : p)    // set the target characters to be consumed
            ++freq[ctoi(c)];

        int r = 0;          // expand the window so it covers n bytes
        while (r < n - 1) 
            --freq[ctoi(s[r++])];
        
        vector<int> ans;
        while (r < m) {
            --freq[ctoi(s[r])]; // consume the character at the new head of the window

            int mask = 0;
            for (int i = 0; i < ALPHABET_LEN && mask == 0; ++i) 
                mask |= freq[i];

            int l = r - n + 1;
            if (mask == 0)   // all characters consumed ? can add to result
                ans.push_back(l);

            ++freq[ctoi(s[l])]; // leave the tail character behind
            ++r;             // push the entire window further
        }
        return ans;
    }
};