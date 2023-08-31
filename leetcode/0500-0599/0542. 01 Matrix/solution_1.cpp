// Approach: Run BFS from each 0 cell.
// TC: O(mn)
// SC: O(mn)
class Solution {
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (mat[i][j] == 0)
                    q.push({i, j});
            
        vector<vector<int>> ans(m, vector<int>(n));
        while (!q.empty()) {
            auto& [i, j] = q.front(); q.pop();
            for (auto& [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (0 <= x && x < m && 0 <= y && y < n) {
                    if (mat[x][y] == 1) {
                        mat[x][y] = 0;
                        ans[x][y] = 1 + ans[i][j];
                        q.push({x, y});
                    }
                }
            }
        }
        return ans;
    }
};