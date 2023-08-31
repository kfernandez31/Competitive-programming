// Approach: On the condition's invalidation, update the result.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1, ans = 1;
        for (int i = 1; i < nums.size(); ++i) 
            if (nums[i - 1] < nums[i])
                ans = max(ans, ++len);
            else
                len = 1;
        return ans;
    }
};