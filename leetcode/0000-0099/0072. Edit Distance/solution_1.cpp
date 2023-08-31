// Approach: Top-down DP w/memo.
// TC: O(mn)
// SC: O(mn)
class Solution {
    int bt(vector<vector<int>>& memo, string& src, int i, string& dst, int j) {
        if (i == src.size()) // insert dst's suffix
            return dst.size() - j;
        if (j == dst.size()) // remove src's suffix
            return src.size() - i;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (src[i] == dst[j]) {
            int do_skip = bt(memo, src, i + 1, dst, j + 1);
            return memo[i][j] = do_skip;
        } else {
            int do_replace = 1 + bt(memo, src, i + 1, dst, j + 1);
            int do_delete  = 1 + bt(memo, src, i + 1, dst, j);
            int do_insert  = 1 + bt(memo, src, i, dst, j + 1);
            return memo[i][j] = min({do_replace, do_delete, do_insert});
        }
    }
public:
    int minDistance(string& src, string& dst) {
        vector<vector<int>> memo(src.size(), vector<int>(dst.size(), -1));
        return bt(memo, src, 0, dst, 0);
    }
};
