#include <bits/stdc++.h>
using namespace std;

const int maxN = 2*1e5;
pair<int, int> arr[maxN];
int n;

int solve() {
    int res = 0;
    auto cmp = [&](pair<int, int> a, pair<int, int> b) { return a.second < b.second;};
    sort(arr, arr + n, cmp);
    int last_snd = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i].first >= last_snd) {
            last_snd = arr[i].second;
            res++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    cout << solve() << "\n";

    return 0;
}
