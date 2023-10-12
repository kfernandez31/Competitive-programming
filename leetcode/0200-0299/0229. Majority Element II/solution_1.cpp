// Approach: Generalized Bayer-Moore voting algorithm.
// TC: O(nk), k - podium size
// SC: O(k)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int fst_elem = -1, fst_cnt = 0, snd_elem = -1, snd_cnt = 0;
        for (int num : nums) {
            if (num == fst_elem)
                ++fst_cnt;
            else if (num == snd_elem)
                ++snd_cnt;
            else if (fst_cnt == 0)
                fst_cnt = 1, fst_elem = num;
            else if (snd_cnt == 0)
                snd_cnt = 1, snd_elem = num;
            else
                --fst_cnt, --snd_cnt;
        }

        vector<int> ans;
        int n = nums.size();
        if (count(nums.begin(), nums.end(), fst_elem) > n / 3)
            ans.push_back(fst_elem);
        if (count(nums.begin(), nums.end(), snd_elem) > n / 3)
            ans.push_back(snd_elem);
        return ans;
    }
};