// Approach: Self-explanatory, in-place.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0, prod = 1;
        for (int num : nums) 
            if (num == 0)
                ++zeros;
            else
                prod *= num;

        if (zeros == 0)
            for (int& num : nums) 
                num = prod / num;
        else if (zeros == 1) 
            for (int& num : nums) 
                num = (num == 0) * prod;
        else 
            fill(nums.begin(), nums.end(), 0);
        
        return nums;
    }
};