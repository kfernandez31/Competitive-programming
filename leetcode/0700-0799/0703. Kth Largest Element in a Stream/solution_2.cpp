// Approach: Minheap.
// TC: construction - O(nlogk), add - logk
// SC: O(k)
class KthLargest {
    int k;
    priority_queue<int> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(-num);
            if (pq.size() == k + 1)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(-val);
        if (pq.size() == k + 1)
            pq.pop();
        return -pq.top();
    }
};