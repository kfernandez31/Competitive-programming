// Approach: Same as solution #1, but with a smaller constant.
// TC: O(n)
// SC: O(n/64) = O(n) (128Kb)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<(int)1e5 + 1> s;
        for (int num : nums) {
            if (s[num])
                return num;
            s.set(num);
        }
        return -1;
    }
};
