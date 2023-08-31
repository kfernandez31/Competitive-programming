// Approach: Binary search on the answer.
// TC: O(nlogk), k - |piles|
// SC: O(1)
class Solution {
public:
    bool check(vector<int>& piles, int k, int h) {
        int sum = 0;
        for (int pile : piles) {
            sum += pile / k + (pile % k != 0);
            if (sum > h)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 0, hi = 1e9 + 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (!check(piles, mid, h))
                lo = mid;
            else 
                hi = mid;
        }
        return hi;
    }
};