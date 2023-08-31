// Approach: Use a stack. The stack contents at any point are [-^*, +^*].
// TC: O(n)
// SC: O(n)
class Solution {
public:
     vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<pair<int, int>> st;
        vector<bool> remaining(n, true);

        for (int i = 0; i < n; ++i) {
            if (0 < asteroids[i])
                st.push({asteroids[i], i});
            else {
                if (!st.empty()) {
                    while (!st.empty() && remaining[i]) {
                        auto& [top, j] = st.top();
                        if (top > -asteroids[i]) 
                            remaining[i] = false;
                        else {
                            remaining[i] = top < -asteroids[i];
                            remaining[j] = false;
                            st.pop();
                        }
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (remaining[i])
                ans.push_back(asteroids[i]);
        return ans;
    }
};