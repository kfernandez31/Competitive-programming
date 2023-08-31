// Approach: Fenwick tree.
// TC: insert - O(logr), findMedian - O(log^2r), r - range of nums
// SC: O(r)
class FenwickTree {
    inline int lsb(int i) { return i & -i; }
    vector<int> data;
public:
    FenwickTree(int n) : data(n + 1) {}

    FenwickTree(const vector<int>& d) : data({0}) {
        data.insert(data.end(), d.begin(), d.end());
        int n = d.size();
        for (int i = 1; i <= n; ++i) {
            int j = i + lsb(i);
            if (j <= n)
                data[j] += data[i];
        }
    }

    int sum(int r) {
        int sum = 0;
        for (; r > 0; r -= lsb(r)) 
            sum += data[r];
        return sum;
    }

    void add(int i, int val) {
        for (; i < data.size(); i += lsb(i)) 
            data[i] += val;
    }

    // binary search for the first cell with k elements up to it
    int get_by_order(int k) {
        int lo = 0, hi = data.size();
        while (hi - lo > 1) { 
            int mid = (lo + hi) / 2;
            if (sum(mid) < k)
                lo = mid;
            else
                hi = mid;
        }
        return hi;
    }
};

class MedianFinder {
    static const int RANGE = 1e5;
    FenwickTree ft;
    int n = 0;
public:
    MedianFinder() : ft(2 * RANGE + 1) {}

    void addNum(int num) {
        ft.add(num + RANGE, 1);
        ++n;
    }

    double findMedian() {
        if (n % 2 == 1)
            return ft.get_by_order(n / 2 + 1) - RANGE;
        else {
            int a = ft.get_by_order(n / 2);
            int b = ft.get_by_order(n / 2 + 1);
            return (a + b) / 2.0 - RANGE;
        } 
    }
};