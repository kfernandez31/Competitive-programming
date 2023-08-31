// Approach: Maintain a queue monotonic over values (non-increasing) and over indices (increasing).
// TC: O(n)
// SC: O(n)
class MonoQueue {
    struct Element { int index, value; };
    deque<Element> dq;
    int k;
public:
    MonoQueue(int k) : k(k), dq(k) {}

    inline void push(int idx, int val) {
        while (!dq.empty() && dq.front().value < val) 
            dq.pop_front();
        dq.push_front({idx, val});
        while (!dq.empty() && idx - dq.back().index >= k) 
            dq.pop_back();
    }

    inline int back() { return dq.back().value; }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        MonoQueue mq(k);

        int i = 0;
        while (i < k) // form a window
            mq.push(i, nums[i++]);
        ans[0] = mq.back();
        
        while (i < n) { // slide it
            mq.push(i, nums[i]);
            ans[++i - k] = mq.back();
        }

        return ans;
    }
};