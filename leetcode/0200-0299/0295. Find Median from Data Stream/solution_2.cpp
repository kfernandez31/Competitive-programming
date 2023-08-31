// Approach: GNU PBDS.
// TC: insert - O(n), findMedian - O(logn)
// SC: O(n)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ;

class MedianFinder {
    ordered_multiset<int> s;
public:
    MedianFinder() {}
    
    void addNum(int num) { s.insert(num); }

    double findMedian() {
        auto it = s.find_by_order(s.size() / 2);
        if (s.size() % 2 == 0) 
            return (*it + *--it) / 2L;
        else
            return (double)*it;
    }
};