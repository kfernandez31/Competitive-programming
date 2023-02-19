#include <bits/stdc++.h>
using namespace std;

#define X true
#define Y false

const int maxN = 5 * 1e5, maxM = 5 * 1e5;
pair<int, bool> cuts[maxN + maxM];
int n, m;

long long solve() {
    long long res = 0ll;
    int cnt[2] = {0, 0};

    sort(cuts, cuts + n + m - 2);

    for (int i = 0; i < n + m - 2; i++) {
        res += (1 + cnt[1 - cuts[i].second]) * cuts[i].first;
        cnt[cuts[i].second]++;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n + m - 2; i++) {
        cin >> cuts[i].first;
        cuts[i].second = (i < n - 1)? X : Y;
    }

    cout << solve() << "\n";
    return 0;
}
