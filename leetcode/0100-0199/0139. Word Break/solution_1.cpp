// Approach: Top-down DP w/memo.
// TC: O(nlk), l - avg. word length, k - |word dict| 
// SC: O(n)
class Solution {
public:
    bool wordBreak(string& s, vector<string>& word_dict) {
        int n = s.size();

        int min_len = 21;
        for (auto& w : word_dict)
            min_len = min(min_len, (int)w.size());
        if (min_len > n)
            return false;

        vector<int> memo(n, -1);
        function<int(int)> bt = [&](int i) {
            if (i >= s.size())
                return 1;

            if (memo[i] != -1)
                return memo[i];

            for (auto& word : word_dict) 
                if (s.find(word, i) == i && bt(i + word.size()))
                    return memo[i] = 1;
            return memo[i] = 0;
        };

        return bt(0);
    }
};