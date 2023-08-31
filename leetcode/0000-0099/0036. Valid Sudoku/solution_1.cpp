// Approach: Check each row, column, and square.
// TC: O(mn)
// SC: O(1)
class Solution {
    #define NDIGITS 9
    inline int ctod(char c) { return c - '1'; }

    bool checkRow(vector<char>& row) {
        bool seen[NDIGITS] = {0};
        for (int i = 0; i < row.size(); ++i) {
            int d = ctod(row[i]);
            if (d >= 0) {
                if (seen[d])
                    return false;
                seen[d] = true;
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int col) {
        bool seen[NDIGITS] = {0};
        for (int i = 0; i < board.size(); ++i) {
            int d = ctod(board[i][col]);
            if (d >= 0) {
                if (seen[d])
                    return false;
                seen[d] = true;
            }
        }
        return true;
    }

    bool checkSquare(vector<vector<char>>& board, int si, int sj) {
        bool seen[NDIGITS] = {0};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int d = ctod(board[si + i][sj + j]);
                if (d >= 0) {
                    if (seen[d])
                        return false;
                    seen[d] = true;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < NDIGITS; ++i)
            if (!checkRow(board[i]) || !checkCol(board, i))
                return false;
        for (int i = 0; i < NDIGITS; i += 3)
            for (int j = 0; j < NDIGITS; j += 3)
                if (!checkSquare(board, i, j))
                    return false;
        return true;
    }
};