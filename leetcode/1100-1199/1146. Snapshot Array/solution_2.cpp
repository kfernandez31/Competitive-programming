// Approach: Like solution #1, but using lower_bound instead.
// TC: set - O(logk), snap - O(1), get - O(logk), k - #snaps
// SC: O(k)
class SnapshotArray {
    vector<map<int, int>> snaps;
    int snap_id = 0;
public:
    SnapshotArray(int length) : snaps(length) {}
    
    void set(int index, int val) {
        snaps[index][-snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        return snaps[index].lower_bound(-snap_id)->second;
    }
};