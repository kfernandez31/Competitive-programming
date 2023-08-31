// Approach: Brute force - linear search.
// TC: O(n) (you can't do better in the worst case: [1,...,1,0,1,...,1])
// SC: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};