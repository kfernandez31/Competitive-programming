// Approach: Maintain a queue of ready tasks, and a second for tasks on cooldown. If the first queue is non-empty, execute its head. If the second queue is non-empty, move its ready tasks to the first queue.
// TC: O(l+n(k+logn)), l - alphabet size
// SC: O(l+n)
class Solution {
    #define ALPHABET_LEN 26
    inline int ctoi(char c) { return c - 'A'; }

    class TaskComparator {
    private:
        int* time_left;
    public:
        TaskComparator(int* time_left) : time_left(time_left) {}

        bool operator()(int a, int b) const {
            return time_left[a] < time_left[b];
        }
    };
public:
    int leastInterval(vector<char>& tasks, int k) {
        int time_left[ALPHABET_LEN] = {};
        int num_left = tasks.size();
        for (char t : tasks)
            ++time_left[ctoi(t)];

        TaskComparator cmp(time_left);
        priority_queue<char, vector<char>, TaskComparator> pq(cmp);
        for (int i = 0; i < ALPHABET_LEN; ++i)
            if (time_left[i] > 0)
                pq.push(i);
        
        int cur_time = 0;
        queue<pair<int, int>> lru;
        for (; num_left > 0; ++cur_time) {
            if (!pq.empty()) { // if any tasks are available, greedily execute the one with the highest count
                int task = pq.top(); pq.pop();
                --num_left;
                if (--time_left[task] > 0)
                    lru.push({cur_time, task});
            }
          
            if (!lru.empty()) { // bring back a task that was on cooldown
                auto& [q_time, q_task] = lru.front();
                if (cur_time - q_time >= k) {
                    pq.push(q_task);
                    lru.pop();
                }
            }
        }
        return cur_time;
    }
};