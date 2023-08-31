// (follow up #1) Approach: A simplification of the Fenwick tree solution. 
// TC: insert - O(1), findMedian - O(r), r - range of nums
// SC: O(r)
class MedianFinder {
    static constexpr int RANGE = 100;
    int cnt[RANGE + 1] = {};
    int n = 0;

    int getKth(int k) {
        int i = 0;
        while (i <= RANGE) 
            if (k <= cnt[i])
                break;
            else
                k -= cnt[i++];
        return i;
    }
public:
    MedianFinder() {}
    
    void addNum(int num) {
        ++cnt[num];
        ++n;
    }

    double findMedian() {
        if (n % 2 == 1)
            return getKth(n / 2 + 1);
        else {
            int a = getKth(n / 2);
            int b = getKth(n / 2 + 1);
            return (a + b) / 2.0;
        }
    }
};