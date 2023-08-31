// Approach: Brute force - always look for the remaining 3 points.
// TC: add - O(1), count - O(|GRID|^2)
// SC: O(|GRID|^2)
class DetectSquares {
    static constexpr int GRID_SIZE = 1000;
    vector<vector<int>> grid;
public:
    DetectSquares() : grid(GRID_SIZE + 1, vector<int>(GRID_SIZE + 1)) {}
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ++grid[x][y];
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x = point[0], y = point[1];
        for (int i = 0; i <= GRID_SIZE; ++i) 
            if (grid[i][y] > 0) 
                for (int j = 0; j <= GRID_SIZE; ++j) 
                    if (grid[x][j] > 0) 
                        if (grid[i][j] > 0) {
                            int x_side = abs(x - i), y_side = abs(y - j);
                            if (x_side == y_side && x_side > 0) 
                                ans += grid[i][y] * grid[x][j] * grid[i][j];
                        }
        return ans;
    }
};