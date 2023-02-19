#include <bits/stdc++.h>
using namespace std;

unordered_set<int> nums;
int n, d;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (nums.count(x - d)) {
            cout << x << " " << x - d << "\n";
            return 0;
        }
        if (nums.count(x + d)) {
            cout << x + d << " " << x << "\n";
            return 0;
        }
        nums.insert(x);
    }

    cout << "NIE\n";

    return 0;
}
