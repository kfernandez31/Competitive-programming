// Approach: For each row, choose a column and recurse.
// TC: O((n+2)!)
// SC: O(n)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1)
            return {{"Q"}};
        if (n == 2 || n == 3)
            return {};

        vector<string> board(n, string(n, '.'));
        auto is_safe = [&](int row, int col) {
            for (int i = 0; i < row; ++i) {
                if (board[i][col] == 'Q')
                    return false;
                int d = row - i;
                if (0 <= col - d && board[i][col - d] == 'Q')
                    return false;
                if (col + d < n  && board[i][col + d] == 'Q')
                    return false;
            }
            return true;
        };

        vector<vector<string>> ans; 
        int nleft = n;
        function<void(int)> bt = [&](int row) {
            if (nleft == 0) {
                ans.push_back(board);
                return;
            }

            for (int col = 0; col < n; ++col) {
                if (is_safe(row, col)) {
                    board[row][col] = 'Q';
                    --nleft;
                    bt(row + 1);
                    board[row][col] = '.';
                    ++nleft;
                }
            }
        };

        bt(0);
        return ans;
    }
};