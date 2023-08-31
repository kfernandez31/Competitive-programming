// Approach: Binary search for the latest non-greater timestamp. The task description specifies that calls to set are monotonic in time, which allows us to use a vector.
// TC: set - O(1), get - O(log(#sets))
// SC: O(#sets)
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m; // key -> [(timestamp, value)]

    void set(string key, string value, int timestamp) {
        m[move(key)].push_back({timestamp, move(value)});
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key))
            return "";
            
        int lo = -1, hi = m[key].size();
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (m[key][mid].first <= timestamp)
                lo = mid;
            else 
                hi = mid;
        }

        return lo == -1 ? "" : m[key][lo].second;
    }
};