// Approach: Map numbers to frequencies, then frequencies to numbers and take the first k values.
// TC: O(n+nsqrt(n)) = O(nsqrt(n))
// SC: O(n+sqrt(n)) = O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_cnt;
        for (int num : nums)
            ++num_to_cnt[num];

        map<int, vector<int>> cnt_to_nums;
        for (auto& [num, cnt] : num_to_cnt) 
            cnt_to_nums[-cnt].push_back(num);

        vector<int> ans;
        for (auto& [_, nums] : cnt_to_nums) {
            for (int num : nums) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;   
    }
};