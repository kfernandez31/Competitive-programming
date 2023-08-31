// Approach: Like solution #1, but compute the prefix max on the fly, and don't compute the suffix one. Instead, notice that the second possible bound is the overall maximum.
// TC: O(3n) = O(n)
// SC: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n       = height.size();
        int ans     = 0;
        int max_h   = height[0];
        int max_idx = 0;
        // find the index of any max
        for (int i = 1; i < n; ++i) {
            if (height[i] > max_h) {
                max_h   = height[i];
                max_idx = i;
            }
        }
        
        int pref_max_h = height[0];
        for (int i = 0; i <= max_idx; ++i) {
            pref_max_h = max(pref_max_h, height[i]);
            ans       += pref_max_h - height[i];
        }

        int suf_max_h = height[n - 1];
        for (int i = n - 1; i > max_idx; --i) {
            suf_max_h = max(suf_max_h, height[i]);
            ans      += suf_max_h - height[i];
        }
        
        return ans;
    }
};