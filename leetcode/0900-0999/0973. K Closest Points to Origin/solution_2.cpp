// Approach: Maintain a maxheap window of size k, slide it over the points, then take its contents.
// TC: nlogk
// SC: O(k)
class Solution {
    int d(vector<int>& p) { return p[0] * p[0] + p[1] * p[1]; }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            pq.push({d(points[i]), i});
            if (pq.size() == k + 1)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto& [d, i] = pq.top(); pq.pop();
            ans.push_back(move(points[i]));
        }

        return ans;
    }
};