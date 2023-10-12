// Approach: When pushing, rotate the stack.
// TC: push - O(n), pop - O(1)
// SC: O(n)
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) 
            q.push(q.front()), q.pop();
    }
    
    int pop() {
        int t = top();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};