// Approach: Similar to solution #1, but run the BFS with a clock that ticks each second. Also, run a preemptive check for connectivity.
// TC: O(mn)
// SC: O(mn)
class Solution {
    int m, n;
    static constexpr pair<int, int> dirs[] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    bool is_valid(int i, int j) {
        return (0 <= i && i < m) && (0 <= j && j < n);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        int num_fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1) {
                    ++num_fresh;

                    bool connected = false;
                    for (auto& [di, dj] : dirs) {
                        int x = i + di;
                        int y = j + dj;
                        if (is_valid(x, y))
                            connected |= grid[x][y];
                    }
                    if (!connected)
                        return - 1;
                }
            }
        }

        int ans = 0;
        for (; !q.empty() && num_fresh; ++ans) {
            int sz = q.size();
            while (sz-- && num_fresh) { // take only oranges that have rotten this second
                auto& [i, j] = q.front(); q.pop();
                for (auto& [di, dj] : dirs) {
                    int x = i + di;
                    int y = j + dj;
                    if (is_valid(x, y) && grid[x][y] == 1) {
                        --num_fresh;
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }

        return num_fresh ? -1 : ans; // this check could be omitted
    }
};