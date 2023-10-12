// Approach: GNU PBDS.
// TC: O(nlogn)
// SC: O(n)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        ordered_multiset<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            ans += s.size() - s.order_of_key({2ll * nums[i], i});
            s.insert({long(nums[i]), i});
        }
        return ans;
    }
};