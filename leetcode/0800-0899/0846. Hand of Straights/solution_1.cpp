// Approach: Mark the currently minimal element as the current group's start and find the remaining k-1 points. Repeat for all groups.
// TC: O(n/k*nk) = O(n^2)
// SC: O(1)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if (k == 1)     return true;
        if (n % k != 0) return false;

        sort(hand.begin(), hand.end());
        int cards_left = n, group_start, group_size = 0, i = 0;
        while (cards_left && i < n) {
            if (hand[i] == -1)
                ++i;
            else if (group_size == 0) {
                --cards_left;
                group_start = hand[i];
                group_size  = 1;
                hand[i]     = -1; // mark as used
                ++i;
            } else {
                int expected_next = group_start + group_size;
                if (hand[i] != expected_next)
                    ++i;
                else {
                    hand[i] = -1; // mark as used
                    --cards_left;
                    if (++group_size == k) {
                        i = 0;
                        group_size = 0;
                    } else
                        ++i;
                }
            }
        }

        return group_size == 0;
    }
};