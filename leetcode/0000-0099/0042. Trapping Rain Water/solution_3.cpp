// Approach: Two pointers.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int max_l = -1, max_r = -1;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            max_l = max(max_l, height[l]);
            max_r = max(max_r, height[r]);
            if (max_l < max_r) 
                ans += max(0, max_l - height[l++]);
            else 
                ans += max(0, max_r - height[r--]);
        }
        return ans;
    }
};