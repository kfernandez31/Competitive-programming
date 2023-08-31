// Approach: Two pointers.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int x = r - l; 
            if (height[l] < height[r]) 
                ans = max(ans, x * height[l++]);
            else 
                ans = max(ans, x * height[r--]);
        }
        return ans;
    }
};