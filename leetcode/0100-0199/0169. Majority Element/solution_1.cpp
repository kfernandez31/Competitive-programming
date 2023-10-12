// Approach: Bayer-Moore voting algorithm.
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_elem, maj_cnt = 0;
        for (int num : nums) 
            if (maj_cnt == 0) 
                maj_cnt = 1, maj_elem = num; 
            else
                maj_cnt += num == maj_elem ? 1 : -1;
        return maj_elem;
    }
};