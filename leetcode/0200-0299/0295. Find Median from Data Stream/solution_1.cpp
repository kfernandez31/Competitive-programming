// Approach: STL.
// TC: insert - O(n), findMedian - O(n)
// SC: O(n)
class MedianFinder {
    multiset<int> s;
public:
    MedianFinder() {}
    
    void addNum(int num) { s.insert(num); }

    double findMedian() {
        auto it = s.begin();
        advance(it, s.size() / 2); // Unfortunately, this is O(n)
        if (s.size() % 2 == 0) 
            return (*it + *(--it)) / 2.0;
        else
            return (double)*it;
    }
};