// Solution 2: Like solution #1, but optimized.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int max_freq = 0;
        for (int num : nums) 
            max_freq = max(max_freq, ++freq[num]);

        vector<vector<int>> groups(max_freq + 1);
        for (auto& [num, cnt] : freq) 
            groups[cnt].push_back(num);

        vector<int> ans;
        for (int cnt = max_freq; cnt > 0; --cnt) {
            for (int num : groups[cnt]) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;   
    }
};