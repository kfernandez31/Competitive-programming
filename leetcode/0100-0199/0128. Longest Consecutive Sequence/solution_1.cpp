// Approach: Calculate the size of each consecutive subsequence starting from its first element.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) 
            s.insert(num);
        
        int ans = 0;
        for (int num : nums) {
            if (!s.count(num - 1)) { // first element of a subsequence
                int size = 1, cur = num;
                while (s.count(++cur)) 
                    ++size;
                ans = max(ans, size);
            }
        }
        return ans;
    }
};