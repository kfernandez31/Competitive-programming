// Approach: Like solution #2 but for any k >= 1.
// TC: O(nk), k - podium size
// SC: O(k)
class Solution {
    static constexpr int K   = 2;
    static constexpr int INF = 1e9 + 1;
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem[K], cnt[K] = {};
        for (int i = 0; i < K; ++i)
            elem[i] = INF;

        for (int num : nums) {
            bool found = false;
            for (int i = 0; i < K && !found; ++i)
                if (num == elem[i])
                    ++cnt[i], found = true;
            if (!found) 
                for (int i = 0; i < K && !found; ++i)
                    if (cnt[i] == 0)
                        cnt[i] = 1, elem[i] = num, found = true;
            if (!found)
                for (int i = 0; i < K; ++i)
                    --cnt[i];
        }

        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < K; ++i) 
            if (elem[i] != INF && count(nums.begin(), nums.end(), elem[i]) > n / (K + 1))
                ans.push_back(elem[i]);
        return ans;
    }
};