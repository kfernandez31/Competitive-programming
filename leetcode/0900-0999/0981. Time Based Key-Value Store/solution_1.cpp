// Approach: STL. This approach supports non-monotonic sets.
// TC: set - O(log(#sets)), get - O(log(#sets))
// SC: O(#sets)
class TimeMap {
public:
    unordered_map<string, map<int, string>> m; // key -> [(timestamp, value)]
    
    void set(string key, string value, int timestamp) {
        m[move(key)][timestamp] = move(value);
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key))
            return "";

        auto it = prev(m[key].upper_bound(timestamp));
        // this check is necessary, as we may have had only > timestamps
        if (it->first <= timestamp)
            return it->second;
        else
            return "";
    }
};