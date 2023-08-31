// Approach: Multiset.
// TC: construction - O(nlogk), add - logk
// SC: O(k)
class KthLargest {
    int k;
    multiset<int> s;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            s.insert(num);
            if (s.size() == k + 1)
                s.erase(s.begin());
        }    
    }
    
    int add(int val) {
        s.insert(val);
        if (s.size() == k + 1)
            s.erase(s.begin());
        return *s.begin();
    }
};