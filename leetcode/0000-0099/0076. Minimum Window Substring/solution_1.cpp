// Approach: Sliding window with two passes - the second one pushes only the tail.
// TC: O(n+km), k - alphabet size
// SC: O(n)
class Solution {
    inline bool match(const int* window_chars, const int* t_chars) {
        bool ans = true;
        for (int i = 0; i < 26 && ans; ++i) {
            ans &= window_chars['a' + i] >= t_chars['a' + i];
            ans &= window_chars['A' + i] >= t_chars['A' + i];
        }
        return ans;
    }
public:
    string minWindow(string& s, string& t) {
        if (t.size() == 1 && s[0] == t[0])
            return s.substr(0, 1);
        
        int t_chars[128] = {};
        for (char c : t)
            ++t_chars[c];
        
        int window_chars[128] = {};
        window_chars[s[0]] = 1;

        int start = 0, min_len = INT_MAX;
        int tail = 0, head = 0, n = s.size();
        while (head < n) {                 // first pass - push both tail and head
            if (!match(window_chars, t_chars)) {
                if (++head < n) 
                    ++window_chars[s[head]];
            } else {
                int cur_len = head - tail + 1;
                if (cur_len < min_len) {
                    start   = tail;
                    min_len = cur_len;
                }
                --window_chars[s[tail++]];
            }
        }

        if (match(window_chars, t_chars)) { // second pass - push only tail
            while (tail < n) {
                --window_chars[s[tail]];
                if (!match(window_chars, t_chars))
                    break;
                else {
                    int cur_len = head - tail + 1;
                    if (cur_len < min_len) {
                        start    = tail;
                        min_len = cur_len;
                    }
                    ++tail;
                }
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};