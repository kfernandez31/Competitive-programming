// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {   
            if (s.contains(num))
                return num;
            s.insert(num);
        }
        return -1;
    }
};