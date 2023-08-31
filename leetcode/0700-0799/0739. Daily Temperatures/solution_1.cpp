// Approach: Maintain a stack monotonic over indices and values (both increasing). Whenever pushing a higher value than the ones on the stack, we obtain the answer for them.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int, int>> st; // (value, index)
        for (int i = 0; i < n; ++i) {
            while (!st.empty()) {
                auto& [temp, j] = st.top();
                if (temp >= temperatures[i]) 
                    break;
                ans[j] = i - j;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};