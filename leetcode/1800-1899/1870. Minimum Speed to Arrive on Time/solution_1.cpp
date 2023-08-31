// Approach: Binary search on the answer.
// TC: O(logn)
// SC: O(1)
class Solution {
    static constexpr int INFTY = 1e7 + 1;
public:
    int minSpeedOnTime(vector<int>& dist, double time_left) {
        int n = dist.size();
        if (time_left <= n - 1)
            return -1;
        
        int lo = 0, hi = 1e7 + 1;
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;

            double time_spent = 0;
            for (int i = 0; i < n - 1; ++i)
                time_spent += ceil((double)dist[i] / mid);  
            time_spent += (double)dist[n - 1] / mid;
            
            if (time_spent > time_left) 
                lo = mid;
            else 
                hi = mid;
        }

        return hi == INFTY ? -1 : hi;
    }
};