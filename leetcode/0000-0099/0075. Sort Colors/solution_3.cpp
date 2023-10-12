// Approach: Like solution #2, but slightly rephrased.
// TC: O(n)
// SC: O(k), k - range of nums
class Solution {
    static constexpr int K = 3;
public:
    void sortColors(vector<int>& nums) {
        int bkt[K + 1] = {};
        for (int num : nums)
            ++bkt[num + 1];
        for (int i = 1; i < K + 1; ++i)
            bkt[i] += bkt[i - 1];
        for (int i = 1; i < K + 1; ++i) 
            for (int j = bkt[i - 1]; j < bkt[i]; ++j)
                nums[j] = i - 1;
    }
};