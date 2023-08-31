// Approach: TODO:
// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i) 
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end());
        
        stack<double> st{{DBL_MIN}};
        for (int i = n - 1; i >= 0; --i) {
            double time = double(target - cars[i].first) / cars[i].second;
            if (st.top() < time)
                st.push(time);
        }

        return st.size() - 1;
    }
};