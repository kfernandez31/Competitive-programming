// Approach: Bucket sort the stones.
// TC: O(nr), r - range of nums. Pessimistic test case: [1, 1, 1, ..., 1, 1000]
// SC: O(r)
class Solution {
    static constexpr int RANGE = 1e3;
public:
    int lastStoneWeight(vector<int>& stones) {
        int weights[RANGE + 1] = {};
        int max_w = 0;
        for (int s : stones) {
            max_w = max(max_w, s);
            ++weights[s];
        }
        
        int cnt = stones.size();
        while (cnt > 1) {
            int y = -1, x = -1;

            while (max_w > 0 && x == -1) {
                if (weights[max_w] == 0)
                    --max_w;
                else {
                    if (y == -1)
                        y = max_w;
                    else
                        x = max_w;

                    --cnt;
                    --weights[max_w];
                }
            }

            int z = y - x;
            if (z > 0) {
                max_w = max(max_w, z);
                ++weights[z];
                ++cnt;
            }
        }

        while (max_w > 0 && weights[max_w] == 0)
            --max_w;

        return max_w;
    }
};