// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if (!s.count(num))
                s.insert(num);
            else
                s.erase(num);
        }
        return *s.begin();
    }
};