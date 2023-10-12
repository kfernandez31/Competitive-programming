// Approach: Bucket sort.
// TC: O(n)
// SC: O(k), k - range of nums
class Solution {
    static constexpr int K = 3;
public:
    void sortColors(vector<int>& nums) {
        int bkt[K] = {};
        for (inst num : nums)
            ++bkt[num];
        
        int i = -1;
        for (int j = 0; j < K; ++j) 
            for (int k = 0; k < bkt[j]; ++k)
                nums[++i] = j;
    }
};