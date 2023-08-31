// Approach: Like solution #1, but more clever. TODO:
// TC: O(k+n), k - alphabet size
// SC: O(k)
class Solution {
    inline int ctoi(char c) { return c - 'A'; }
public:
    int characterReplacement(string& s, int k) {
        int n = s.size(), ans = 0;

        int freq[26] = {};
        freq[ctoi(s[0])] = 1;

        int max_freq = 1;
        int tail = 0, head = 0;
        while (head < n) {
            int others = head - tail + 1 - max_freq;
            if (others <= k) {
                ans = max(ans, head - tail + 1);
                if (++head < n)
                    max_freq = max(max_freq, ++freq[ctoi(s[head])]);
            } else 
                --freq[ctoi(s[tail++])];
        }
        return ans;
    }
};
