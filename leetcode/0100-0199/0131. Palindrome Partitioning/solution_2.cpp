// Approach: Like solution #1, but with precomputation.
// TC: O(n * 2^n)
// SC: O(n)
class Solution {
    inline bool is_palindrome(string& s, int l, int r) {
        while (l < r) 
            if (s[l++] != s[r--]) 
                return false;
        return true;
    }
public:
    vector<vector<string>> partition(string& s) {
        vector<vector<string>> ans;
        vector<string> acc;
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, 0));
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                pal[i][j] = is_palindrome(s, i, j);
            
        function<void(int)> bt = [&](int start) {
            if (start == n) {
                ans.push_back(acc);
                return;
            }

            for (int end = start; end < n; ++end) {
                if (pal[start][end]) {
                    acc.push_back(s.substr(start, end - start + 1));
                    bt(end + 1);
                    acc.pop_back();
                }
            }
        };

        bt(0);
        return ans;
    }
};