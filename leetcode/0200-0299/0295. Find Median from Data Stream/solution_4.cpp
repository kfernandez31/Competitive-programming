// Approach: Fenwick tree w/binary lifting.
// TC: insert - O(logr), findMedian - O(logr), r - range of nums
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


    int get_by_order(int k) {
        int sum = 0, pos = 0;
        for (int i = log2(data.size()); i >= 0; --i) {
            int new_pos = pos + (1 << i);
            if (new_pos < data.size() && sum + data[new_pos] < k) {
                sum += data[new_pos];
                pos  = new_pos;
            }
        }
        return pos + 1;
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