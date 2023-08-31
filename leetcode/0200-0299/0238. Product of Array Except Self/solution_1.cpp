// Approach: Prefix and suffix products.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prefProd[n], suffProd[n];
        prefProd[0]     = nums[0];
        suffProd[n - 1] = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            prefProd[i]         = prefProd[i - 1] * nums[i];
            suffProd[n - 1 - i] = suffProd[n - i] * nums[n - 1 - i];
        }
        
        vector<int> ans(n);
        ans[0]     = suffProd[1];
        ans[n - 1] = prefProd[n - 2];
        for (int i = 1; i < n - 1; ++i) 
            ans[i] = prefProd[i - 1] * suffProd[i + 1];
        return ans;
    }
};