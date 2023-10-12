// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& queries, vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i) 
            idx[nums[i]] = i;

        stack<int> st;
        vector<int> gre(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() < nums[i])
                st.pop();
            gre[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }

        vector<int> ans;
        for (int q : queries) 
            ans.push_back(gre[idx[q]]);
        return ans;
    }
};