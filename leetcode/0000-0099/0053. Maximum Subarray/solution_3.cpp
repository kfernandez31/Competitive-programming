// Approach: Divide and conquer.
// TC: O(n)
// SC: O(logn)
class Solution {
    using tiii = tuple<int, int, int>;
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9 - 1;

        function<tiii(int, int)> aux = [&](int l, int r) -> tiii {
            if (l == r) {
                int num = nums[l];
                ans = max(ans, num);
                return {num, num, num};
            }
            int mid = (l + r) / 2;
            auto [l_sum, l_pref, l_suff] = aux(l, mid);
            auto [r_sum, r_pref, r_suff] = aux(mid + 1, r);
            ans = max(ans, l_suff + r_pref);
            return {
                l_sum + r_sum, 
                max(l_pref, l_sum + r_pref), 
                max(r_suff, r_sum + l_suff)
            };
        };

        aux(0, nums.size() - 1);
        return ans;
    }
};