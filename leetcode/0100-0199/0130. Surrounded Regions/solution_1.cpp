// Approach: Start DFS from all 'O's on the border, flipping them to some temporary '#'. All remaining 'O's didn't have a cell on the border, and thus they were captured.
// TC: O(mn)
// SC: O(mn)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        function<void(int, int)> dfs = [&](int i, int j) {
            if ((i < 0 || m <= i) || (j < 0 || n <= j))
                return;
            if (board[i][j] != 'O')
                return;
            board[i][j] = '#'; // mark as visited, will correct later
            for (auto& [di, dj] : dirs) 
                dfs(i + di, j + dj, board);
        };

        for (int i = 0; i < m; ++i) 
            dfs(i, 0), dfs(i, n - 1);
        for (int j = 0; j < n; ++j)
            dfs(0, j), dfs(m - 1, j);
        
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if (board[i][j] == '#') 
                    board[i][j] = 'O';
    }
};