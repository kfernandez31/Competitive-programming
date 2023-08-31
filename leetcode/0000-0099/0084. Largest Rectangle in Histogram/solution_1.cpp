// Approach: Monostack.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<pair<int, int>> st;
        int n = heights.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int last_j = i;
            while (!st.empty()) { 
                auto& [j, h] = st.top();
                if (h < heights[i])
                    break;
                st.pop();
                ans    = max(ans, h * (i - j));
                last_j = j;
            }
            st.emplace(last_j, heights[i]);
        }

        return ans;
    }
};