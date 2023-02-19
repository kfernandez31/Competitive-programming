#include <bits/stdc++.h>
using namespace std;

#define LSB(x) ((x) & 1)

const int maxN = 1e6 + 7;
const int maxM = 1e9 + 7;
int prices[maxN];
long long suf[maxN];
int suf_min[2][maxN];
int pref_max[2][maxN];
int m, n;

void preprocess() {
    pref_max[0][0] = pref_max[1][0] = INT_MIN;
    suf_min[0][0]  = suf_min[1][0]  = INT_MAX;

    for (int i = 1; i <= n; i++) {
        suf[i] = suf[i - 1] + prices[n - i + 1];

        if (LSB(prices[i])) {
            pref_max[0][i] = pref_max[0][i - 1];
            pref_max[1][i] = max(pref_max[1][i - 1], prices[i]);
        } else {
            pref_max[1][i] = pref_max[1][i - 1];
            pref_max[0][i] = max(pref_max[0][i - 1], prices[i]);
        }

        if (LSB(prices[n - i + 1])) {
            suf_min[0][i] = suf_min[0][i - 1];
            suf_min[1][i] = min(suf_min[1][i - 1], prices[n - i + 1]);
        } else {
            suf_min[1][i] = suf_min[1][i - 1];
            suf_min[0][i] = min(suf_min[0][i - 1], prices[n - i + 1]);
        }
    }
}

long long solve(int k) {
    if (LSB(suf[k])) {
        return suf[k];
    } else {
        long long res1 = -1, res2 = -1;
        if (suf_min[0][k] != INT_MAX && pref_max[1][n - k] != INT_MIN) {
            res1 = suf[k];
            res1 += pref_max[1][n - k];
            res1 -= suf_min[0][k];
        } 
        if (suf_min[1][k] != INT_MAX && pref_max[0][n - k] != INT_MIN) {
            res2 = suf[k];
            res2 += pref_max[0][n - k];
            res2 -= suf_min[1][k]; 
        }
        return max(res1, res2);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
    
    preprocess();

    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        cout << solve(k) << "\n";
    }
    
    return 0;
}