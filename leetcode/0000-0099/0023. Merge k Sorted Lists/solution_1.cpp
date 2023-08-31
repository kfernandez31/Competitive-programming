// Approach: Maintain a minheap of lists' heads. When popping a head, push its tail if it's non-empty.
// TC: O(k*l*logk), l - avg. list length
// SC: O(k)
class Solution {
public:
    //O(k*max|L|*logk), O(\sum|L|*logk)       
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        for (auto& l : lists)
            if (l) pq.push({-l->val, l});

        ListNode *ans = nullptr, *temp = nullptr;
        while (!pq.empty()) {
            auto& [val, l] = pq.top(); pq.pop();
            
            if (!ans)
                ans = temp = l;
            else
                temp = temp->next = l;

            if (l->next)
                pq.push({-l->next->val, l->next});
        }        
        return ans;
    }
};