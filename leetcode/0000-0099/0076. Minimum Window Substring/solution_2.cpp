// Approach: Sliding window with a single pass.
// TC: O(n+m)
// SC: O(k), k - alphabet size
class Solution {
public:
    string minWindow(string& s, string& t) {
        int freq[128] = {};
        for (char c : t) 
            ++freq[c];
        
        int cnt_diff = 0;
        for (int cnt : freq)
            cnt_diff += (cnt > 0);
        
        int start = 0, min_len = INT_MAX;
        int tail = 0, head = -1, n = s.size();

        while (head < n) {
            if (cnt_diff > 0) {
                if (++head < n && --freq[s[head]] == 0)
                    --cnt_diff;
            } else {
                int cur_len = head - tail + 1;
                if (cur_len < min_len) { // try to improve the result
                    start   = tail;
                    min_len = cur_len;
                }
                if (++freq[s[tail++]] == 1)
                    ++cnt_diff;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};