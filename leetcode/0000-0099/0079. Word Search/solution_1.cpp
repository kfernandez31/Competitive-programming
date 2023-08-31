// Approach: Simple backtracking.
// TC: O(mn*4^k), k - |word|
// SC: O(k)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    bool exist(vector<vector<char>>& grid, string& word) {
        int m = grid.size(), n = grid[0].size(), k = word.size();

        function<bool(int, int, string&, int)> bt = [&](int i, int j, int idx) {
            if (idx == k) 
                return true;
            if ((i < 0 || m <= i) || (j < 0 || n <= j))
                return false;
            if (grid[i][j] != word[idx])
                return false;

            char marker = '#';
            swap(grid[i][j], marker); // mark as visited

            for (auto& [di, dj] : dirs) 
                if (bt(i + di, j + dj, idx + 1))
                    return true;
        
            swap(grid[i][j], marker); // unmark
            return false;
        }

        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (bt(i, j, 0))
                    return true;
        return false;
    }
};