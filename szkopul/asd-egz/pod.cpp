#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int n, k;
int arr[maxN];
unordered_map<int, int> cnt;

void insert(int x) {
    auto it = cnt.find(x);
    if (it == cnt.end()) {
        cnt.insert({x, 1});
    } else {
        cnt[x]++;
    }
}

void remove(int x) {
    if (cnt[x] == 1) {
        cnt.erase(x);
    } else {
        auto it = cnt.find(x);
        cnt[x]--;
    }
}

long long solve() {
    long long res = 0;
    int tail = 0;
    int head = 0;
    insert(arr[0]);

    while (head < n) {
        if (cnt.size() <= k) {
            res += head - tail + 1;
            head++;
            if (head < n) {
                insert(arr[head]);
            }
        } else {
            remove(arr[tail]);
            tail++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve() << "\n";

    return 0;
}
