// Approach: Hashmap & std::list.
// TC: get - O(1), put - O(1)
// SC: O(n)
class LRUCache {
    using lru_list = list<pair<int, int>>;
    unordered_map<int, lru_list::iterator> m;

    lru_list l; 
    int capacity;

    lru_list::iterator get_node(int key) {
        if (!m.count(key))
            return l.end();
        auto it = m[key];
        l.push_front(*it);
        m[key] = l.begin();
        l.erase(it);
        return m[key];
    }
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        auto it = get_node(key);
        return it == l.end() ? -1 : it->second;
    }
    
    void put(int key, int value) {
        auto it = get_node(key);
        if (it != l.end())
            it->second = value;
        else {
            l.push_front({key, value});
            m[key] = l.begin();
            if (m.size() > capacity) {
                m.erase(l.back().first);
                l.pop_back();
            }
        }
    }
};