// Approach: Sliding window with a single pass.
// TC: O(n+m)
// SC: O(k), k - alphabet size
class Solution {
public:
    string minWindow(const string& s, const string& t) {
        int freq[128] = {};
        for (char c : t)
            ++freq[c];

        int num_left = 0;
        for (int cnt : freq)
            num_left += cnt > 0;

        int m = s.size();
        int start = 0, min_len = m + 1; 
        int tail = 0, head = -1;
        while (head < m) {
            if (num_left > 0) {
                num_left -= (++head < m && --freq[s[head]] == 0);
            } else {
                int len = head - tail + 1;
                if (len < min_len) 
                    start = tail, min_len = len;
                num_left += (++freq[s[tail++]] == 1);
            }
        }
        return min_len == m + 1 ? "" : s.substr(start, min_len);
    }
};