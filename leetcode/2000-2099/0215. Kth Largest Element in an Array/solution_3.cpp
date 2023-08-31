// Approach: Maintain a minheap window of size k, slide it over nums, then take its top.
// TC: O(nlogk)
// SC: O(k)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int num : nums) {
        pq.push(-num);
        if (pq.size() == k + 1)
            pq.pop();
    }
    return -pq.top();
};