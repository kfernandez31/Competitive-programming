// Approach: Run BFS and count the vertices reachable from both oceans (reverse the water flow).
// TC: O(mn)
// SC: O(2mn) = O(mn)
class Solution {
    #define pacific  first
    #define atlantic second
    using pbb = pair<bool, bool>;
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<pbb>> visited(m, vector<pbb>(n));
        queue<pair<int, int>> q;
    
        for (int i = 0; i < m; ++i) {
            visited[i][0].pacific = true;
            q.push({i, 0});
            visited[i][n - 1].atlantic = true;
            q.push({i, n - 1});
        }

        for (int j = 0; j < n; ++j) {
            visited[0][j].pacific = true;
            q.push({0, j});
            visited[m - 1][j].atlantic = true;
            q.push({m - 1, j});
        }

        while (!q.empty()) {
            auto& [i, j] = q.front(); q.pop();
            for (auto& [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (0 <= x && x < m && 0 <= y && y < n) {
                    if (heights[i][j] <= heights[x][y]) { // reverse the condition - water must flow into the ocean!
                        if (visited[i][j] != visited[x][y]) {
                            visited[x][y].pacific  |= visited[i][j].pacific;
                            visited[x][y].atlantic |= visited[i][j].atlantic;
                            q.push({x, y});
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (visited[i][j].pacific && visited[i][j].atlantic)
                    ans.push_back({i, j});
        return ans;
    }
};