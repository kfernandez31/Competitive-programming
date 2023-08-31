// Approach: Sliding window with two passes - first, expand the window to cover m elements, then push both its ends.
// TC: O(m+n)
// SC: O(k), k - alphabet size
// Approach: Perform two passes - first, expand the window to cover m elements, then push both its ends.
// TC: O(m+n)
// SC: O(k), k - alphabet size
class Solution {
    static const int ALPHABET_LEN = 26;
    inline int ctoi(char c) { return c - 'a'; }
public:
    bool checkInclusion(string& s, string& t) {
        const int n = t.size();
        if (n < s.size())
            return false;
        
        int p_chars[ALPHABET_LEN] = {};
        for (char c : s)
            ++p_chars[ctoi(c)];

        int head = 0, window_chars[ALPHABET_LEN] = {};
        while (head < n && head < s.size()) // first pass - expand the window
            ++window_chars[ctoi(t[head++])];

        int cnt_diff = 0;
        for (int i = 0; i < ALPHABET_LEN; ++i)
            cnt_diff += window_chars[i] != p_chars[i];

        if (cnt_diff == 0)  
            return true;                    // may have already found the permutation

        for (; head < n; ++head) {          // second pass - push both tail and head
            int i = ctoi(t[head]);
            ++window_chars[i];
            if (window_chars[i] == p_chars[i] + 1)
                ++cnt_diff;
            else if (window_chars[i] == p_chars[i])
                --cnt_diff;
            
            int tail = head - s.size();
            i = ctoi(t[tail]);
            --window_chars[i];
            if (window_chars[i] == p_chars[i] - 1)
                ++cnt_diff;
            else if (window_chars[i] == p_chars[i])
                --cnt_diff;

            if (cnt_diff == 0)  
                return true;
        }
        return false;
    }
};