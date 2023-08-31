// Approach: Keep nodes on a stack, then dump the stack, interleaving half of it with half of the list.
// TC: O(n)
// SC: O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur = head;
        for (; cur; cur = cur->next) 
            st.push(cur);

        cur = head;
        int n = st.size();
        for (int i = 0; i < n / 2; ++i) {
            ListNode* next = cur->next;
            cur->next       = st.top();
            cur->next->next = next;
            cur = next;
            st.pop();
        }
        cur->next = nullptr;
    }
};