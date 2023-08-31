// Approach: Maintain two heaps (one min, other max) of roughly equal size. Their tops make up the median.
// TC: insert - O(logn), findMedian - O(1)
// SC: O(n)
class MedianFinder {
    priority_queue<int> left, right; // left - maxheap, right - minheap 
public:
    MedianFinder() {}
    
    void addNum(int num) {
        // this also works:
        // if (right.empty() || num < -right.top())
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(-num);

        if (left.size() == right.size() + 2) {
            right.push(-left.top());
            left.pop();
        } else if (left.size() + 2 == right.size()) {
            left.push(-right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + -right.top()) / 2.0;
        else if (left.size() == right.size() + 1)
            return left.top();
        else // if (left.size() + 1 == right.size())
            return -right.top();
    }
};