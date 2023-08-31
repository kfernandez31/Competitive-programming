// Approach: Like solution #1, but more clever.
// TC: O(nlogn)
// SC: O(n)
class Solution {
public: 
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if (k == 1)     return true;
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int card : hand)
            ++freq[card];
        
        while (!freq.empty()) {
            int group_start = freq.begin()->first;
            for (int i = 0; i < k; ++i) { // complete the group
                if (freq[group_start + i] == 0)
                    return false;
                if (--freq[group_start + i] == 0)
                    freq.erase(group_start + i);
            }
        }
        return true;
    }
};