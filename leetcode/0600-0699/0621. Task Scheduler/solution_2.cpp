// Approach: TODO.
// TC: O(l+n), l - alphabet size
// SC: O(l+n)
class Solution {
    #define ALPHABET_LEN 26
    inline int ctoi(char c) { return c - 'A'; }
public:
    int leastInterval(vector<char>& tasks, int k) {
        int cnt[ALPHABET_LEN] = {};
        for (char t : tasks)
            ++cnt[ctoi(t)];

        int max_cnt = *max_element(cnt, cnt + ALPHABET_LEN);
        int cnt_max = count(cnt, cnt + ALPHABET_LEN, max_cnt);

        int num_regular_chunks = max_cnt - 1;
        int regular_chunk_len  = k + 1;
        int bonus_chunk_len    = cnt_max;
        int all_chunks_len     = (num_regular_chunks) * regular_chunk_len + bonus_chunk_len;
        return max((int)tasks.size(), all_chunks_len);
    }
};