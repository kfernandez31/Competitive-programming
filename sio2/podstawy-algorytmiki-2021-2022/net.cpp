#include <bits/stdc++.h>
using namespace std;

const string NONE = "";

unordered_map<string, string> parent;
unordered_map<string, int> set_size;

string find_set(string v) {
    if (parent.find(v) == parent.end()) {
        return NONE;
    }
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(string x, string y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) {
        if (set_size[x] < set_size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        set_size[x] += set_size[y];
    }
}

void make_set(string v) {
    parent[v] = v;
    set_size[v] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        string command, a, b;
        cin >> command >> a >> b;
        if (command == "connect") {
            if (find_set(a) == NONE) make_set(a);
            if (find_set(b) == NONE) make_set(b);
            union_sets(a, b);
        } else /*if (command == "sending")*/ {
            auto a_set = find_set(a);
            auto b_set = find_set(b);

            if (a != b && (a_set == NONE || b_set == NONE)) {
                cout << "Nie\n";
            } else {
                cout << (a_set == b_set? "Tak" : "Nie") << "\n";
            }
        }
    }

    return 0;
}
