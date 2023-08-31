// Approach: Store the stones in a maxheap.
// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone : stones)
            pq.push(stone);
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            int z = y - x;
            if (z > 0)
                pq.push(z);
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};