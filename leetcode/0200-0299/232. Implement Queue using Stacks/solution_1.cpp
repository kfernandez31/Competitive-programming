// Approach: Maintain two stacks, "pour" from one to another if can't pop from the other.
// TC: push - O(1), pop - O(1) amortized
// SC: O(n)
class MyQueue {
    stack<int> in, out;
public:    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int top = peek();
        out.pop();
        return top;
    }
    
    int peek() {
        if (out.empty()) 
            while (!in.empty()) 
                out.push(in.top()), in.pop();
        return out.top(); 
    }
    
    bool empty() {
        return out.empty() && in.empty();
    }
};