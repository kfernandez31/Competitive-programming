// Approach: "Patience (solitaire) sort"
// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis = {int(-1e4 - 1)};
        for (int num : nums) 
            if (lis.back() < num)
                lis.push_back(num);
            else
                *lower_bound(lis.begin(), lis.end(), num) = num;
        return lis.size() - 1;
    }
};
