// Approach: Hashmap & handmade doubly-linked list.
// TC: get - O(1), put - O(1)
// SC: O(n)
class LRUCache {
    struct ListNode {
        int key, val;
        ListNode *prev, *next;
        ListNode(int key, int val, ListNode* prev = nullptr, ListNode* next = nullptr) 
            : key(key), val(val), prev(prev), next(next) {}
    };

    unordered_map<int, ListNode*> m;
    ListNode *front, *back;
    int capacity;

    ListNode* get_node(int key) {
        if (!m.count(key)) 
            return nullptr;

        ListNode* node = m[key];

        if (node != front) {
            if (node == back) // pop the back
                back = back->prev;
            else { // skip over the node
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            // push to front
            front->prev = node;
            node->next  = front;
            front       = node;
        }
        
        return node;
    }
public:
    LRUCache(int capacity): capacity(capacity), front(nullptr), back(nullptr) {}
    ~LRUCache() { for (auto& [_, v] : m) delete v; }
    
    int get(int key) {
        ListNode* node = get_node(key);
        return node ? node->val : -1;
    }
    
    void put(int key, int value) {
        ListNode* node = get_node(key);
        if (node)
            node->val = value;
        else {
            ListNode* node = new ListNode(key, value, nullptr, front);
            if (!back)
                back = node;
            if (front) 
                front->prev = node;
            m[key] = front = node;
            if (m.size() > capacity) {
                back = back->prev;
                m.erase(back->next->key);
                delete back->next;
                back->next = nullptr;
            }
        }
    }
};