// Approach: Compute prefix and suffix maxima. Water in each cell is bounded the smaller maximum.
// TC: O(n)
// SC: O(2n) = O(n)
class Solution {
public:
    /****** Solution 1: prefix/suffis maximums ******/
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pref_max(n), suf_max(n);

        pref_max[0]    = height[0];
        suf_max[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            pref_max[i]        = max(pref_max[i - 1], height[i]);
            suf_max[n - 1 - i] = max(suf_max[n - i],  height[n - 1 - i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) 
            ans += min(pref_max[i], suf_max[i]) - height[i]; 
        
        return ans;
    }
};