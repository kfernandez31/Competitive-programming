// Approach: Maintain a dictionary of the numbers and check if the current one is already stored.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(x))
                return true;
            s.insert(x);
        }
        return false;
    }
};