// Approach: Divide the array into segments reachable in 1,2,...,k jumps.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, ans = 0;
        while (right < n - 1) {
            int farthest = 0;
            for (int i = left; i <= right; ++i) 
                farthest = max(farthest, i + nums[i]);
            left  = right + 1;
            right = farthest;
            ++ans;
        }
        return ans;
    }
};
