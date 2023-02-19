#include <bits/stdc++.h>
using namespace std;

const int maxN = 4 * 1e4;
const int maxM = 50;
int n, m;
bitset<maxM> players[maxN + 1];
unordered_set<bitset<maxM>> bitmaps;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--) {
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            players[p].set(m, i < n / 2);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (bitmaps.find(players[i]) != bitmaps.end()){
            cout << "NIE\n";
            return 0;
        }
        bitmaps.insert(players[i]);
    }

    cout << "TAK\n";
    return 0;
}