// Approach: Diagonal expansion.
// TC: add - O(1), count - O(|GRID|sqrt2) = O(|GRID|)
// SC: O(|GRID|^2)
class DetectSquares {
    static constexpr int GRID_SIZE = 1000;
    static constexpr pair<int, int> dxy[] = {{+1,+1}, {+1,-1}, {-1,-1}, {-1,+1}};
    vector<vector<int>> grid;

    static inline bool in_bounds(int x) { return 0 <= x && x <= GRID_SIZE; }
public:
    DetectSquares() : grid(GRID_SIZE + 1, vector<int>(GRID_SIZE + 1)) {}
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ++grid[x][y];
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        bool done = false;
        for (int d = 1; d <= GRID_SIZE && !done; ++d) {
            done = true;
            for (auto& [dx, dy] : dxy) {
                int _x = x + d * dx, _y = y + d * dy;
                if (in_bounds(_x) && in_bounds(_y)) {
                    ans += grid[_x][y] * grid[x][_y] * grid[_x][_y];
                    done = false;
                }
            }
        }
        return ans;
    }
};