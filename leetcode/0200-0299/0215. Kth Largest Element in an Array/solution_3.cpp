// Approach: Use a minheap as window over the largest elements.
// TC: O(nlogk)
// SC: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(-num);
            if (pq.size() == k + 1)
                pq.pop();
        }
        return -pq.top();
    }
};