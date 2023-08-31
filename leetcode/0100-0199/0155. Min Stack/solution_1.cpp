// Approach: Store both the value and the current min on the stack.
// TC: push - O(1), pop - O(1), top - O(1), getMin - O(1)
// SC: O(n)
class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() : st({{42, INT_MAX}}) {}
    
    void push(int val) {
        st.push({val, min(val, st.top().second)});
    }
    
    void pop()    { st.pop(); }
    int  top()    { return st.top().first; }
    int  getMin() { return st.top().second; }
};