// Approach: Monotonic stack.
// TC: O(1) amortized
// SC: O(n)
class StockSpanner {
    stack<pair<int, int>> st;
public:
    int next(int price) {
        int span = 1;
        while (!st.empty()) {
            auto [elem, cnt] = st.top();
            if (elem > price)
                break;
            span += cnt;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};