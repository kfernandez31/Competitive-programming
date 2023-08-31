// Approach: For each second point, count the two remaining.
// TC: add - O(1), count - O(#insertions)
// SC: O(#insertions)
class DetectSquares {
    unordered_map<int, unordered_map<int, int>> grid;
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ++grid[x][y];
    }
    
    int count(vector<int> point) {
        int ans = 0, x = point[0], y = point[1];
        for (auto& [_y, cnt]: grid[x]) { // pick point #1 above/below
            if (_y == y) 
                continue;
            int d = abs(y - _y);
            // pick points #2 and #3 
            //             a) on the left                       b) on the right
            ans  += cnt * ((grid[x - d][y] * grid[x - d][_y]) + (grid[x + d][y] * grid[x + d][_y]));
        }
        return ans;
    }
};