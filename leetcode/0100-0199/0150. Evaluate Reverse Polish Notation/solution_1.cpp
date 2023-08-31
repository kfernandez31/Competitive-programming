// Approach: Straightforward.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& tok : tokens) {
            int res;
            try { res = stoi(tok); } 
            catch (...) {
                int rhs = st.top(); st.pop();
                int lhs = st.top(); st.pop();
                if (tok[0] == '+')
                    res = lhs + rhs;
                else if (tok[0] == '-')
                    res = lhs - rhs;
                else if (tok[0] == '*')
                    res = lhs * rhs;
                else
                    res = lhs / rhs;
            }
            st.push(res);
        }
        return st.top();
    }
};