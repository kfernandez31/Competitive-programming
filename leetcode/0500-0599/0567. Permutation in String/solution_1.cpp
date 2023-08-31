// Approach: Sliding window of size m.
// TC: O(m+kn), k - alphabet size
// SC: O(k)
class Solution {
    static const int ALPHABET_LEN = 26;
    inline int ctoi(char c) { return c - 'a'; }
public:
    bool checkInclusion(string& s, string& t) {
        int window[ALPHABET_LEN] = {};
        for (char c : s) 
            ++window[ctoi(s)];
        
        int tail = 0, head = 0, m = s.size(), n = t.size();
        for (;head < n; ++head) {
            --window[ctoi(t[head])];

            if (head - tail + 1 == m) {
                bool all_zero = true;
                for (int i = 0; i < ALPHABET_LEN && all_zero; ++i)
                    all_zero &= window[i] == 0;
                if (all_zero)
                    return true;

                ++window[ctoi(t[tail++])];
            }               
        }
        return false;
    }
};